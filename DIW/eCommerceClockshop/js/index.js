  async function fetchProducts(url, limit = 9) {
    try {
      const response = await fetch(url);
      const data = await response.json();
      const products = data.products.slice(0, limit);
      return products;
    } catch (error) {
      console.log('Erro ao obter os produtos:', error);
    }
  }

  function generateProductHTML(product) {
    return `
      <a href="detalhes.html?id=${product.id}">
        <div class="align-content-center product col-lg-3 col-6 col-md-4 product-card">
          <div class="card mb-lg-5 border border-dark border-1" style="width:auto;">
            <img class="card-img-top p-2" src="${product.image}" alt="Card de ${product.title}">
            <div class="card-body py-0">
              <p class="card-text my-0">${product.title}</p>
              ${generateStarsHTML(product.rating)}
              <span>(${product.rating.count})</span>
              <p class="mt-1">
                <span class="me-1"><strong>R$ ${product.price}</strong></span>
                <s class="d-block d-sm-inline-block">R$ ${product.price * 2}</s>
              </p>
            </div>
          </div>
        </div>
      </a>
    `;
  }  

  function generateWatchesHTML(product) {
    return `<div class="row my-4">
    <div class="col-xxl-4 col-xl-4 col-lg-5 col-6 col-md-6">
      <a href="detalhes.html?id=${product.id}"><img class="img-fluid rounded-1" src="${product.image}" width="auto" alt="Card de ${product.title}"></a>
    </div>
    <div class="col-xxl-8 col-xl-8 col-lg-7 ps-3 col-6 col-md-6">
      <p class="card-text my-0"><a href="detalhes.html?id=${product.id}">${product.title}</a></p>
      ${generateStarsHTML(product.rating)}
      <span>(${product.rating.count})</span>
      <h6 class="mt-1">R$ ${product.price}</h6>
    </div>
    </div>
    `
  }

  function generateStarsHTML(rating) {
    const fullStars = Math.floor(rating.rate);
    const hasHalfStar = rating.rate - fullStars >= 0.5;

    let starsHTML = '';
    for (let i = 0; i < fullStars; i++) {
      starsHTML += '<span class="fa fa-star checked fa-xs"></span>';
    }
    if (hasHalfStar) {
      starsHTML += '<span class="fa fa-star-half checked fa-xs"></span>';
    }
    return starsHTML;
  }


  async function renderProducts() {
    const productsContainer = document.getElementById('products-container');
    const relogiosavaliados = document.getElementById('relogios-avaliados');

    const allProductsUrl = 'https://diwserver.vps.webdock.cloud/products/category/Accessories%20-%20Watches';
    const watchesUrl = 'https://diwserver.vps.webdock.cloud/products/category/Accessories%20-%20Watches?page=50';

    const allProducts = await fetchProducts(allProductsUrl);
    const watches = await fetchProducts(watchesUrl, 5);

    if (!allProducts || !watches) {
      productsContainer.innerHTML = '<p>Erro ao carregar os produtos.</p>';
      return;
    }

    let allProductsHTML = '';
    let watchesHTML = '';

    allProducts.forEach(product => {
      allProductsHTML += generateProductHTML(product);
    });

    watches.forEach(product => {
      watchesHTML += generateWatchesHTML(product);
    });

    productsContainer.innerHTML = allProductsHTML;
    relogiosavaliados.innerHTML = watchesHTML;
  }

  renderProducts();

  function fetchAndPopulateFilters() {
    const productsUrl = 'https://diwserver.vps.webdock.cloud/products/category/Accessories%20-%20Watches';
    const productsUrl2 = 'https://diwserver.vps.webdock.cloud/products/category/Accessories%20-%20Watches?page=50';
  
    function addUniqueOption(select, value) {
      const options = Array.from(select.options);
      if (!options.some(option => option.value === value)) {
        const newOption = document.createElement('option');
        newOption.value = value;
        newOption.text = value;
        select.add(newOption);
      }
    }
  
    fetch(productsUrl)
      .then(response => response.json())
      .then(jsonResponse => {
        const products = jsonResponse.products; 
        const selectBrand = document.getElementById('select-brand');
        const selectGender = document.getElementById('select-gender');
        const selectColor = document.getElementById('select-color');
  
        products.forEach(product => {
          addUniqueOption(selectBrand, product.brandName);
          addUniqueOption(selectGender, product.gender);
          addUniqueOption(selectColor, product.baseColour);
        });
      })
      .catch(error => {
        console.error('Erro ao buscar os dados dos produtos:', error);
      });

      fetch(productsUrl2)
      .then(response => response.json())
      .then(jsonResponse => {
        const products = jsonResponse.products; 
        const selectBrand = document.getElementById('select-brand');
        const selectGender = document.getElementById('select-gender');
        const selectColor = document.getElementById('select-color');
  
        products.forEach(product => {
          addUniqueOption(selectBrand, product.brandName);
          addUniqueOption(selectGender, product.gender);
          addUniqueOption(selectColor, product.baseColour);
        });
      })
      .catch(error => {
        console.error('Erro ao buscar os dados dos produtos:', error);
      });
  }
  

document.addEventListener('DOMContentLoaded', fetchAndPopulateFilters);

function redirectToSearchPageFilter() {

  const selectBrand = document.getElementById('select-brand');
  const selectGender = document.getElementById('select-gender');
  const selectColor = document.getElementById('select-color');

  const brand = selectBrand.value;
  const gender = selectGender.value;
  const color = selectColor.value;

  const queryParams = new URLSearchParams({
    brand,
    gender,
    color
  });

  window.location.href = `pesquisa.html?${queryParams.toString()}`;
}

function redirectToSearchPageSearchBar() {
  const searchInput = document.getElementById('search-input');
  const searchQuery = searchInput.value.trim();

  const queryParams = new URLSearchParams({
    search: searchQuery 
  });

  window.location.href = `pesquisa.html?${queryParams.toString()}`;
}

document.getElementById('caixa-de-pesquisa').addEventListener('submit', function (event) {
  event.preventDefault();
  redirectToSearchPageSearchBar();
});
document.getElementById('pesquisa-filtro').addEventListener('click', redirectToSearchPageFilter);


function getQueryParams() {
  const queryParams = new URLSearchParams(window.location.search);
  return {
    brand: queryParams.get('brand') || '',
    gender: queryParams.get('gender') || '',
    color: queryParams.get('color') || '',
    search: queryParams.get('search') || ''
  };
}

function filterProducts(products, queryParams) {
  return products.filter(product => {
    return (
      (!queryParams.brand || product.brandName === queryParams.brand) &&
      (!queryParams.gender || product.gender === queryParams.gender) &&
      (!queryParams.color || product.baseColour === queryParams.color) &&
      (!queryParams.search || product.title.toLowerCase().includes(queryParams.search.toLowerCase()))
    );
  });
}

function fetchAndDisplayFilteredProducts() {
  const productsUrl = 'https://diwserver.vps.webdock.cloud/products/category/Accessories%20-%20Watches';
  const productsUrl2 = 'https://diwserver.vps.webdock.cloud/products/category/Accessories%20-%20Watches?page=50';

  Promise.all([fetch(productsUrl), fetch(productsUrl2)])
    .then(responses => Promise.all(responses.map(response => response.json())))
    .then(jsonResponses => {
      const queryParams = getQueryParams();
      const filteredProducts = filterProducts(jsonResponses.flatMap(response => response.products), queryParams);
      if (filteredProducts.length === 0) {
        displayNoResultsMessage();
      } else {
        displayProducts(filteredProducts);
      }
    })
    .catch(error => {
      console.error('Erro ao buscar os dados dos produtos:', error);
    });
}

function displayNoResultsMessage() {
  const productList = document.getElementById('product-list');
  productList.innerHTML = '<p class="text-white">Nenhum resultado encontrado para a pesquisa correspondente.</p>';
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

function displayProducts(products) {
  const productList = document.getElementById('product-list');

  products.forEach(product => {
    productList.innerHTML += generateProductHTML(product);
  });
}

fetchAndDisplayFilteredProducts();

function redirectToSearchPage() {
  const searchInput = document.getElementById('search-input');
  const searchQuery = searchInput.value.trim();

  const queryParams = new URLSearchParams({
    search: searchQuery 
  });

  window.location.href = `pesquisa.html?${queryParams.toString()}`;
}

document.getElementById('caixa-de-pesquisa').addEventListener('submit', function (event) {
  event.preventDefault();
  redirectToSearchPage();
});

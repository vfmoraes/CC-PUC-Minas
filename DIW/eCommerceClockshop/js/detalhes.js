const params = new URLSearchParams(window.location.search);
const productId = params.get("id");

fetch(`https://diwserver.vps.webdock.cloud/products/${productId}`)
  .then(response => response.json())
  .then(product => {
    console.log(product);
    const imageElement = document.getElementById("product-image");
    imageElement.src = product.image;
    document.getElementById("product-title").innerHTML = product.title;
    document.getElementById("product-description").innerHTML = product.description;
    document.getElementById("product-brand").innerHTML = `Marca: ${product.brandName}`;
    document.getElementById("product-gender").innerHTML = `Gênero: ${product.gender}`;
    document.getElementById("product-color").innerHTML = `Cor: ${product.baseColour}`;
    document.getElementById("product-rating").innerHTML = generateStarsHTML(product.rating);
    document.getElementById("product-price").innerHTML = `R$ ${product.price}`;
    document.getElementById("product-discount").innerHTML = `R$ ${product.price * 2}`;
  })
  .catch(error => {
    console.error("Erro ao obter detalhes do produto:", error);
  });

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

  const countHTML = `<span class="text-white ms-2 rating-count">(${rating.count})</span>`;
  return starsHTML + countHTML;
}

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

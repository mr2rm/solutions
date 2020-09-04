const main = document.getElementById('root');

function renderProducts(products) {
  main.innerHTML = products
    .map(
      product => `<div class="product" data-product-id="${product.id}">
                    <h1>${product.title}</h1>
                    <p class="price">${product.price} تومان</p>
                    <p class="date">${product.date}</p>
                  </div>`
    )
    .join('');
}

const products = [
  {
    id: 1,
    title: 'محصول اول',
    price: '32000',
    date: '1596902113'
  },
  {
    id: 2,
    title: 'محصول دوم',
    price: '46000',
    date: '1555891200'
  },
  {
    id: 3,
    title: 'محصول سوم',
    price: '20000',
    date: '1515369600'
  },
  {
    id: 4,
    title: 'محصول چهارم',
    price: '88000',
    date: '1509580800'
  },
  {
    id: 5,
    title: 'محصول پنجم',
    price: '11000',
    date: '1477267200'
  }
];

renderProducts(products);

document
  .getElementById('changeProducts')
  .addEventListener('click', changeProducts);

function changeProducts() {
  renderProducts(products.map(item => {
    date = new Date(item.date * 1000)
    return {
      ...item,
      price: item.price / 2,
      date: date.toLocaleDateString()
    }
  }))
}

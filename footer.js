const footerHTML = `
  <footer class="section-footer">
    <div class="footer-container container">
      <div class="content_1">
        <img src="public/images/logo.png" alt="logo" />
        <p>
          Welcome to farmers marketplace, <br />
          your ultimate destination for
          <br />
          fresh and quality products!
        </p>
        <img src="https://i.postimg.cc/Nj9dgJ98/cards.png" alt="cards" />
      </div>
      <div class="content_2">
        <h4>SHOPPING</h4>
        <a href="#">Fruits and veggies</a>
        <a href="#">Organic products</a>
        <a href="#">Homemade Products</a>
        <a href="#">Seasonal Specials</a>
      </div>
      <div class="content_3">
        <h4>Experience</h4>
        <a href="./contact.html">Contact Us</a>
        <a href="" target="_blank"> Payment Method </a>
        <a href="" target="_blank"> Delivery </a>
        <a href="" target="_blank"> Return and Exchange </a>
      </div>
      <div class="content_4">
        <h4>NEWSLETTER</h4>
        <p>
          Be the first to to eat healthy , live healthy !
         
        </p>
        <div class="f-mail">
          <input type="email" placeholder="Your Email" />
          <i class="bx bx-envelope"></i>
        </div>
        <hr />
      </div>
    </div>
    <div class="f-design">
      <div class="f-design-txt">
        <p>Design and Code by SURAJ AND SHRADDHA : ICC-G10, VIT,PUNE </p>
      </div>
    </div>
  </footer>`;

const footerElem = document.querySelector(".section-footer");
footerElem.insertAdjacentHTML("afterbegin", footerHTML);

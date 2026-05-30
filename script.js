const toggleBtn = document.querySelector(".menu-toggle");
const navLinks = document.getElementById("navLinks");

toggleBtn.addEventListener("click", () => {
  navLinks.classList.toggle("show");
});



let index = 0;

function getSlides(){
    return document.querySelectorAll(".slide");
}

function showSlide(i){
    const slides = getSlides();

    slides.forEach((s, idx) => {
        s.style.display = (idx === i) ? "block" : "none";
    });
}

function nextSlide(){
    const slides = getSlides();
    index = (index + 1) % slides.length;
    showSlide(index);
}

function prevSlide(){
    const slides = getSlides();
    index = (index - 1 + slides.length) % slides.length;
    showSlide(index);
}

// IMPORTANT: expose globally (fixes your error)
window.nextSlide = nextSlide;
window.prevSlide = prevSlide;

window.onload = () => showSlide(index);







// JSON to store data for each image
const artworkData = {
    "artworks": [
        {
            "id": 1,
            "image": "assets/images/artworks/digital1.jpg",
            "title": "Mystic Forest",
            "artist": "Sofia Garcia",
            "heart": 981,
            "comment": 87,
            "view": "3.5k",
            "tags": ["DigitalPainting", "Fantasy", "Nature"],
            "description": "A whimsical forest bathed in golden mist, evoking childhood dreams and forgotten myths. Step carefully—some trees are said to whisper your name."
        },
        {
            "id": 2,
            "image": "assets/images/artworks/digital2.jpg",
            "title": "Urban Dreams",
            "artist": "Marcus Chen",
            "heart": 431,
            "comment": 35,
            "view": "1.8k",
            "tags": ["DigitalPainting", "Urban", "Architecture"],
            "description": "A surreal glimpse into the heart of a neon-lit metropolis where reality melts into imagination. Concrete meets contemplation in every corner."
        },
        {
            "id": 3,
            "image": "assets/images/artworks/digital3.jpg",
            "title": "Lost Memories",
            "artist": "Elena Martinez",
            "heart": 297,
            "comment": 22,
            "view": "1.1k",
            "tags": ["DigitalPainting", "Abstract", "Memory"],
            "description": "Fragments of forgotten days swirl in a cascade of abstract emotion. Each stroke is a piece of a puzzle you'll never quite finish."
        },
        {
            "id": 4,
            "image": "assets/images/artworks/digital4.jpg",
            "title": "Celestial Guardians",
            "artist": "Jamal Wright",
            "heart": 888,
            "comment": 76,
            "view": "3.2k",
            "tags": ["DigitalPainting", "Celestial", "Fantasy"],
            "description": "Towering beings protect the stars from chaos beyond the veil. A fantasy universe where light battles ancient shadows."
        },
        {
            "id": 5,
            "image": "assets/images/artworks/digital5.jpg",
            "title": "Dawn Whispers",
            "artist": "Aisha Patel",
            "heart": 623,
            "comment": 51,
            "view": "2.1k",
            "tags": ["DigitalPainting", "Nature", "Dawn"],
            "description": "The sun speaks in gentle hues of orange and lavender, quietly painting the world awake. A serene tribute to nature's most magical hour."
        },
        {
            "id": 6,
            "image": "assets/images/artworks/concept1.jpg",
            "title": "Mech Warrior",
            "artist": "Alex Hudson",
            "heart": 745,
            "comment": 67,
            "view": "2.7k",
            "tags": ["ConceptArt", "Sci-Fi", "Mech"],
            "description": "Forged in steel and fire, this towering mech guards the last outpost of humanity. Power and precision, rendered in every pixel."
        },
        {
            "id": 7,
            "image": "assets/images/artworks/concept2.jpg",
            "title": "Dragon Realm",
            "artist": "Sophia Chen",
            "heart": 923,
            "comment": 94,
            "view": "4.1k",
            "tags": ["ConceptArt", "Fantasy", "Dragons"],
            "description": "A world where dragons soar between floating islands and magic crackles in the air. Enter if you dare—few return unchanged."
        },
        {
            "id": 8,
            "image": "assets/images/artworks/concept3.jpg",
            "title": "Neon City",
            "artist": "Liam Patel",
            "heart": 512,
            "comment": 39,
            "view": "1.9k",
            "tags": ["ConceptArt", "Cyberpunk", "Urban"],
            "description": "In the city that never sleeps, color is currency and secrets are stored in circuit boards. Where humanity hums with electricity."
        },
        {
            "id": 9,
            "image": "assets/images/artworks/concept4.jpg",
            "title": "Space Explorer",
            "artist": "Olivia Kim",
            "heart": 658,
            "comment": 48,
            "view": "2.4k",
            "tags": ["ConceptArt", "Space", "Sci-Fi"],
            "description": "A lone voyager drifting among the stars, seeking meaning in the silence of the void. Every pixel echoes the infinity beyond."
        },
        {
            "id": 10,
            "image": "assets/images/artworks/concept5.jpg",
            "title": "Fantasy Creatures",
            "artist": "Tyler Johnson",
            "heart": 581,
            "comment": 42,
            "view": "2.2k",
            "tags": ["ConceptArt", "Fantasy", "Creatures"],
            "description": "From elegant phoenixes to mischievous imps, a bestiary of the imagination comes to life. Magic has never looked this wild."
        },
        {
            "id": 11,
            "image": "assets/images/artworks/pixel1.jpg",
            "title": "Retro Adventure",
            "artist": "David Lee",
            "heart": 348,
            "comment": 28,
            "view": "1.3k",
            "tags": ["PixelArt", "Retro", "Gaming"],
            "description": "A nostalgic ride through 8-bit forests and dungeons, complete with secret keys and pixelated glory. Press Start to remember."
        },
        {
            "id": 12,
            "image": "assets/images/artworks/pixel2.jpg",
            "title": "Pixel Landscape",
            "artist": "Maria Rodriguez",
            "heart": 264,
            "comment": 19,
            "view": "1.0k",
            "tags": ["PixelArt", "Landscape", "Nature"],
            "description": "Tiny squares, massive beauty. This peaceful pixel landscape captures the warmth of a sunset on a crisp mountain range."
        },
        {
            "id": 13,
            "image": "assets/images/artworks/pixel3.jpg",
            "title": "8-Bit Heroes",
            "artist": "Jin Park",
            "heart": 392,
            "comment": 33,
            "view": "1.6k",
            "tags": ["PixelArt", "8-Bit", "Characters"],
            "description": "Meet your pixelated champions, from sword-wielding warriors to laser-eyed robots. Justice comes in 16 colors or less."
        },
        {
            "id": 14,
            "image": "assets/images/artworks/pixel4.jpg",
            "title": "Pixelated Dreams",
            "artist": "Sarah Johnson",
            "heart": 471,
            "comment": 40,
            "view": "1.7k",
            "tags": ["PixelArt", "Fantasy", "Dreams"],
            "description": "Sleepy castles, glowing stars, and mysterious forests—crafted from pixels but bursting with emotion. Like dreaming in 2D."
        },
        {
            "id": 15,
            "image": "assets/images/artworks/pixel5.jpg",
            "title": "Arcade Memories",
            "artist": "Ryan Kim",
            "heart": 310,
            "comment": 26,
            "view": "1.4k",
            "tags": ["PixelArt", "Arcade", "Retro"],
            "description": "Insert coin and rewind time. Classic arcade nostalgia rendered in pixel-perfect style—beeps, boops, and boss battles included."
        },
        {
            "id": 16,
            "image": "assets/images/artworks/artwork1.jpg",
            "title": "Digital Landscape",
            "artist": "Elena Martinez",
            "heart": 524,
            "comment": 43,
            "view": "2.0k",
            "tags": ["Featured", "Landscape", "Digital"],
            "description": "An expansive digital painting capturing a world between reality and fantasy, where mountains float and rivers glow."
        },
        {
            "id": 17,
            "image": "assets/images/artworks/artwork2.jpg",
            "title": "Cyberpunk City",
            "artist": "Jamal Wright",
            "heart": 689,
            "comment": 59,
            "view": "2.6k",
            "tags": ["Featured", "Cyberpunk", "Urban"],
            "description": "Blinding lights and rainy nights—this cityscape pulses with the rhythm of a neon heartbeat. Tomorrow looks glitchy and gorgeous."
        },
        {
            "id": 18,
            "image": "assets/images/artworks/artwork3.jpg",
            "title": "Fantasy Character",
            "artist": "Sophia Chen",
            "heart": 793,
            "comment": 70,
            "view": "3.0k",
            "tags": ["Featured", "Fantasy", "Character"],
            "description": "A mysterious heroine with wind-tossed hair and eyes full of secrets. Her story is written in pixels and whispered by dragons."
        },
        {
            "id": 19,
            "image": "assets/images/artworks/artwork4.jpg",
            "title": "Abstract Emotions",
            "artist": "Marcus Johnson",
            "heart": 438,
            "comment": 36,
            "view": "1.5k",
            "tags": ["Featured", "Abstract", "Emotions"],
            "description": "Shapes twist and clash in a vibrant storm of feeling. It's like trying to explain love and fear using only color."
        },
        {
            "id": 20,
            "image": "assets/images/artworks/artwork5.jpg",
            "title": "Futuristic Mech",
            "artist": "Liam Patel",
            "heart": 851,
            "comment": 73,
            "view": "3.3k",
            "tags": ["Featured", "Sci-Fi", "Mech"],
            "description": "Sleek, deadly, and oddly beautiful. This futuristic mech looks like it could star in its own blockbuster—or overthrow a planet."
        }
    ]
  };

document.addEventListener('DOMContentLoaded', function() {
    // Slideshow
    const slides = document.querySelectorAll('.slide');
    const indicators = document.querySelectorAll('.indicator');
    const prevBtn = document.querySelector('.prev-slide');
    const nextBtn = document.querySelector('.next-slide');
    let currentSlide = 0;
    let slideInterval;

    function startSlideshow() {
        slideInterval = setInterval(nextSlide, 5000);
    }

    function stopSlideshow() {
        clearInterval(slideInterval);
    }

    function showSlide(index) {
        slides.forEach(slide => slide.classList.remove('active'));
        indicators.forEach(indicator => indicator.classList.remove('active'));
        
        slides[index].classList.add('active');
        indicators[index].classList.add('active');
        
        currentSlide = index;
    }

    function nextSlide() {
        let next = currentSlide + 1;
        if (next >= slides.length) {
            next = 0;
        }
        showSlide(next);
    }

    function prevSlide() {
        let prev = currentSlide - 1;
        if (prev < 0) {
            prev = slides.length - 1;
        }
        showSlide(prev);
    }

    // Checking assets for slideshow
    if(slides.length > 0 && indicators.length > 0) {
        prevBtn.addEventListener('click', function() {
            stopSlideshow();
            prevSlide();
            startSlideshow();
        });

        nextBtn.addEventListener('click', function() {
            stopSlideshow();
            nextSlide();
            startSlideshow();
        });

        indicators.forEach((indicator, index) => {
            indicator.addEventListener('click', function() {
                stopSlideshow();
                showSlide(index);
                startSlideshow();
            });
        });
        
        startSlideshow();
    }

    // Function to get random artworks from JSON
    function getRandomArtworks(count) {
        // Create a copy of the artworks array to avoid modifying the original
        const allArtworks = [...artworkData.artworks];
        
        // Shuffle the array using Fisher-Yates algorithm
        for (let i = allArtworks.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [allArtworks[i], allArtworks[j]] = [allArtworks[j], allArtworks[i]];
        }
        
        // Return the first 'count' artworks
        return allArtworks.slice(0, count);
    }
    
    // Function to populate the homepage with random artworks
    function populateHomePageArtworks() {
        const featuredSection = document.querySelector('.featured-section .artwork-grid');
        if (!featuredSection) return;
        
        // Get 5 random artworks
        const randomArtworks = getRandomArtworks(5);
        
        // Clear existing content
        featuredSection.innerHTML = '';
        
        // Add random artworks to the featured section
        randomArtworks.forEach(artwork => {
            const card = document.createElement('div');
            card.className = 'artwork-card';
            card.setAttribute('data-artwork-id', artwork.id);
            
            card.innerHTML = `
                <div class="artwork-image">
                    <img src="${artwork.image}" alt="${artwork.title}">
                </div>
                <div class="artwork-info">
                    <h3>${artwork.title}</h3>
                    <p class="artist">by ${artwork.artist}</p>
                    <div class="artwork-stats">
                        <span><i class="fas fa-heart"></i> <span>${artwork.heart}</span></span>
                        <span><i class="fas fa-comment"></i> <span>${artwork.comment}</span></span>
                        <span><i class="fas fa-eye"></i> <span>${artwork.view}</span></span>
                    </div>
                </div>
            `;
            
            featuredSection.appendChild(card);
        });
        
        // Attach event listeners to the new cards
        attachModalEventListeners();
    }

    // Check if we're on the gallery page
    const gallerySection = document.querySelector('.gallery-section');
    if (gallerySection) {
        // Function to load artwork data from our JSON
        function loadArtworkFromJSON() {
            try {
                // Get all tag sections
                const digitalSection = document.querySelector('#Digital').closest('.tag-section').querySelector('.artwork-grid');
                const conceptSection = document.querySelector('#Concept').closest('.tag-section').querySelector('.artwork-grid');
                const pixelSection = document.querySelector('#Pixel').closest('.tag-section').querySelector('.artwork-grid');
                
                if (!digitalSection || !conceptSection || !pixelSection) return;
                
                // Clear existing content
                digitalSection.innerHTML = '';
                conceptSection.innerHTML = '';
                pixelSection.innerHTML = '';
                
                // Populate sections with data from JSON
                artworkData.artworks.forEach(artwork => {
                    const artworkHTML = createArtworkCard(artwork);
                    
                    // Determine which section to add the artwork to
                    if (artwork.tags.includes('DigitalPainting') && artwork.id <= 5) {
                        digitalSection.innerHTML += artworkHTML;
                    } else if (artwork.tags.includes('ConceptArt') && artwork.id >= 6 && artwork.id <= 10) {
                        conceptSection.innerHTML += artworkHTML;
                    } else if (artwork.tags.includes('PixelArt') && artwork.id >= 11 && artwork.id <= 15) {
                        pixelSection.innerHTML += artworkHTML;
                    }
                });
                
                // Reattach event listeners to the new cards
                attachModalEventListeners();
                
                console.log('Artwork data loaded successfully from JSON');
            } catch (error) {
                console.error('Error loading artwork data:', error);
            }
        }
        
        // Call function to load artwork data for gallery page
        if (typeof artworkData !== 'undefined') {
            loadArtworkFromJSON();
        } else {
            console.error('Artwork data not found. Make sure artwork-data.js is loaded before this script.');
        }
    } else {
        // If we're not on the gallery page, we're on the homepage
        // Load random artworks for the homepage
        populateHomePageArtworks();
    }
    
    // Function to create an artwork card HTML from JSON data
    function createArtworkCard(artwork) {
        return `
            <div class="artwork-card" data-artwork-id="${artwork.id}">
                <div class="artwork-image">
                    <img src="${artwork.image}" alt="${artwork.title}">
                </div>
                <div class="artwork-info">
                    <h3>${artwork.title}</h3>
                    <p class="artist">by ${artwork.artist}</p>
                    <div class="artwork-stats">
                        <span><i class="fas fa-heart"></i> <span>${artwork.heart}</span></span>
                        <span><i class="fas fa-comment"></i> <span>${artwork.comment}</span></span>
                        <span><i class="fas fa-eye"></i> <span>${artwork.view}</span></span>
                    </div>
                </div>
            </div>
        `;
    }
    
    // Function to attach event listeners to artwork cards for modal functionality
    function attachModalEventListeners() {
        const artworkCards = document.querySelectorAll('.artwork-card');
        const artworkModal = document.getElementById('artwork-modal');
        if (!artworkModal) return;
        
        const modalImage = document.getElementById('modal-image');
        const modalTitle = document.getElementById('modal-title');
        const modalArtist = document.getElementById('modal-artist');
        const modalLikes = document.getElementById('modal-likes');
        const modalComments = document.getElementById('modal-comments');
        const modalViews = document.getElementById('modal-views');
        const modalDescription = document.getElementById('modal-description');
        const modalTags = document.querySelector('.artwork-tags');
        
        artworkCards.forEach(card => {
            card.addEventListener('click', function() {
                const artworkId = parseInt(this.getAttribute('data-artwork-id'));
                
                // Find the artwork data from our JSON
                const artwork = artworkData.artworks.find(art => art.id === artworkId);
                
                // If we found artwork data in our JSON, use it
                if (artwork) {
                    // Update modal with artwork data
                    modalImage.setAttribute('src', artwork.image);
                    modalImage.setAttribute('alt', artwork.title);
                    modalTitle.textContent = artwork.title;
                    modalArtist.textContent = `by ${artwork.artist}`;
                    modalLikes.textContent = artwork.heart;
                    modalComments.textContent = artwork.comment;
                    modalViews.textContent = artwork.view;
                    modalDescription.textContent = artwork.description;
                    
                    // Update tags if the element exists
                    if (modalTags) {
                        modalTags.innerHTML = '';
                        artwork.tags.forEach(tag => {
                            const tagSpan = document.createElement('span');
                            tagSpan.className = 'tag';
                            tagSpan.textContent = `#${tag}`;
                            modalTags.appendChild(tagSpan);
                        });
                    }
                } else {
                    // Fallback to getting data from the card itself
                    const image = this.querySelector('img').getAttribute('src');
                    const title = this.querySelector('h3').textContent;
                    const artist = this.querySelector('.artist').textContent;
                    const likes = this.querySelector('.fa-heart + span').textContent;
                    const comments = this.querySelector('.fa-comment + span').textContent;
                    const views = this.querySelector('.fa-eye + span').textContent;
    
                    modalImage.setAttribute('src', image);
                    modalImage.setAttribute('alt', title);
                    modalTitle.textContent = title;
                    modalArtist.textContent = artist;
                    if (modalLikes) modalLikes.textContent = likes;
                    if (modalComments) modalComments.textContent = comments;
                    if (modalViews) modalViews.textContent = views;
                    if (modalDescription) modalDescription.textContent = "No description available";
                }
                
                // Display modal
                artworkModal.style.display = 'block';
                document.body.style.overflow = 'hidden';
            });
        });
    }

    // Art modal
    const closeModal = document.querySelector('.close-modal');
    const artworkModal = document.getElementById('artwork-modal');

    if(closeModal) {
        closeModal.addEventListener('click', function() {
            artworkModal.style.display = 'none';
            document.body.style.overflow = 'auto';
        });
    }

    if(artworkModal) {
        window.addEventListener('click', function(event) {
            if (event.target === artworkModal) {
                artworkModal.style.display = 'none';
                document.body.style.overflow = 'auto';
            }
        });
        document.addEventListener('keydown', function(event) {
            if (event.key === 'Escape' && artworkModal.style.display === 'block') {
                artworkModal.style.display = 'none';
                document.body.style.overflow = 'auto';
            }
        });
    }

    // Toggle for mobile
    const menuToggle = document.querySelector('.menu-toggle');
    const navList = document.querySelector('.nav-list');
    const body = document.body;

    if(menuToggle && navList) {
        menuToggle.addEventListener('click', function() {
            menuToggle.classList.toggle('active');
            navList.classList.toggle('active');
            body.classList.toggle('menu-open');
        });

        document.addEventListener('click', function(event) {
            if (body.classList.contains('menu-open') && 
                !event.target.closest('.nav-list') && 
                !event.target.closest('.menu-toggle')) {
                menuToggle.classList.remove('active');
                navList.classList.remove('active');
                body.classList.remove('menu-open');
            }
        });

        window.addEventListener('resize', function() {
            if (window.innerWidth > 768) {
                menuToggle.classList.remove('active');
                navList.classList.remove('active');
                body.classList.remove('menu-open');
            }
        });
    }

    // Smooth scrolling effect
    document.querySelectorAll('a[href^="#"]').forEach(anchor => {
        anchor.addEventListener('click', function(e) {
            if (this.getAttribute('href') !== '#') {
                e.preventDefault();
                const target = document.querySelector(this.getAttribute('href'));
                if (target) {
                    window.scrollTo({
                        top: target.offsetTop - 80,
                        behavior: 'smooth'
                    });
                }
            }
        });
    });

    // Loading for Artwork
    const lazyImages = document.querySelectorAll('.artwork-image img');
    
    if ('IntersectionObserver' in window && lazyImages.length > 0) {
        const imageObserver = new IntersectionObserver((entries, observer) => {
            entries.forEach(entry => {
                if (entry.isIntersecting) {
                    const img = entry.target;
                    const parent = img.parentElement;
                    
                    parent.classList.add('loading');
                    
                    const src = img.getAttribute('src');
                    img.setAttribute('data-src', src);
                    
                    setTimeout(() => {
                        parent.classList.remove('loading');
                        img.setAttribute('src', img.getAttribute('data-src'));
                        observer.unobserve(img);
                    }, 500);
                }
            });
        });
        
        lazyImages.forEach(img => {
            imageObserver.observe(img);
        });
    }

    // Animation
    if ('IntersectionObserver' in window) {
        const animatedElements = document.querySelectorAll('.artwork-card, .tag, section h2');
        
        if(animatedElements.length > 0) {
            const fadeObserver = new IntersectionObserver((entries) => {
                entries.forEach(entry => {
                    if (entry.isIntersecting) {
                        entry.target.style.animation = 'fadeIn 0.8s ease forwards';
                    }
                });
            }, {
                threshold: 0.1
            });
            
            animatedElements.forEach(el => {
                el.style.opacity = '0';
                fadeObserver.observe(el);
            });
        }
    }

    // Upload file
    const fileInput = document.getElementById('artwork');
    const fileName = document.getElementById('file-name');
    const uploadButton = document.querySelector('.upload-button');

    if (uploadButton && fileInput) {
        uploadButton.addEventListener('click', function() {
            fileInput.click();
        });
    }

    if (fileInput) {
        fileInput.addEventListener('change', function() {
            if (fileInput.files.length > 0) {
                fileName.textContent = fileInput.files[0].name;
                fileName.classList.add('file-selected');
            } else {
                fileName.textContent = 'No file chosen';
                fileName.classList.remove('file-selected');
            }
        });
    }
    
    window.dispatchEvent(new Event('resize'));
});
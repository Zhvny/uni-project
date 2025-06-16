
document.addEventListener('DOMContentLoaded', function() {
    // Form validation
    const form = document.getElementById('artwork-submission-form');
    const emailInput = document.getElementById('email');
    const titleInput = document.getElementById('title');
    const descriptionInput = document.getElementById('description');
    const tagsInput = document.getElementById('tags');
    const artworkInput = document.getElementById('artwork');
    const aiRadios = document.getElementsByName('ai-generated');
    const formMessage = document.getElementById('form-message');
    
    // Tag management
    const tagInput = document.getElementById('tags');
    let tagContainer = document.createElement('div');
    tagContainer.className = 'tag-container';
    
    // Create suggestions container
    const tagSuggestions = document.createElement('div');
    tagSuggestions.className = 'tag-suggestions';
    tagSuggestions.style.display = 'none';
    
    // Insert elements into the DOM
    tagsInput.parentNode.insertBefore(tagContainer, tagsInput.nextSibling);
    tagsInput.parentNode.insertBefore(tagSuggestions, tagContainer.nextSibling);
    
    // Suggestions
    const suggestions = [
        'Digital Painting', 'Illustration', 'Concept Art', 'Character Design', 
        'Landscape', 'Portrait', 'Fantasy', 'SciFi', 'Animation',
        'Traditional', 'Painting', 'Sketch', 'Abstract', 'Minimalist',
        'Photography', 'Nature', 'Urban', 'Surreal', 'Stable Diffusion'
    ];
    
    let activeTags = [];
    
    // File upload handling
    const uploadButton = document.querySelector('.upload-button');
    const fileName = document.getElementById('file-name');
    
    if (uploadButton && artworkInput) {
        uploadButton.addEventListener('click', function() {
            artworkInput.click();
        });
        
        artworkInput.addEventListener('change', function() {
            if (this.files && this.files[0]) {
                fileName.textContent = this.files[0].name;
                fileName.classList.add('file-selected');
                validateInput(artworkInput);
            }
        });
    }
    
    // Form submission
    if (form) {
        form.addEventListener('submit', function(e) {
            e.preventDefault();
            
            // Reset previous errors
            resetErrors();
            
            // Validate all inputs
            let isValid = validateForm();
            
            if (isValid) {
                // Show success message
                showFormMessage('Your artwork has been submitted successfully!', 'success');
                
                // Reset form
                setTimeout(() => {
                    form.reset();
                    resetTagContainer();
                    fileName.textContent = 'No file chosen';
                    fileName.classList.remove('file-selected');
                }, 1500);
            }
        });
    }
    
    // Input event listeners
    if (emailInput) emailInput.addEventListener('blur', function() { validateInput(this); });
    if (titleInput) titleInput.addEventListener('blur', function() { validateInput(this); });
    if (descriptionInput) descriptionInput.addEventListener('blur', function() { validateInput(this); });
    if (tagsInput) {
        tagsInput.addEventListener('keydown', handleTagInput);
        tagsInput.addEventListener('input', showTagSuggestions);
        tagsInput.addEventListener('focus', showTagSuggestions);
        tagsInput.addEventListener('blur', function(e) {
            // Delay hiding suggestions to allow for clicking on them
            setTimeout(() => {
                tagSuggestions.style.display = 'none';
                // Fix for positioning issues - restore normal flow
                tagSuggestions.style.position = 'absolute';
                adjustPositioning();
            }, 200);
        });
        
        // Close suggestions when clicking elsewhere
        document.addEventListener('click', function(e) {
            if (!tagSuggestions.contains(e.target) && e.target !== tagsInput) {
                tagSuggestions.style.display = 'none';
                // Fix for positioning issues - restore normal flow
                tagSuggestions.style.position = 'absolute';
                adjustPositioning();
            }
        });
    }
    
    // Helper functions
    function validateForm() {
        let isValid = true;
        
        // Validate each input
        if (!validateInput(emailInput)) isValid = false;
        if (!validateInput(titleInput)) isValid = false;
        if (!validateInput(descriptionInput)) isValid = false;
        
        // Validate tags (either through input or active tags)
        if (activeTags.length === 0 && !validateInput(tagsInput)) {
            isValid = false;
        }
        
        // Validate file
        if (!artworkInput.files || !artworkInput.files[0]) {
            showError(artworkInput, 'Please upload an artwork image');
            isValid = false;
        }
        
        // Validate AI generation radio
        let aiSelected = false;
        for (let radio of aiRadios) {
            if (radio.checked) {
                aiSelected = true;
                break;
            }
        }
        
        if (!aiSelected) {
            showError(aiRadios[0], 'Please indicate if this is AI-generated');
            isValid = false;
        }
        
        return isValid;
    }
    
    function validateInput(input) {
        if (!input) return false;
        
        const value = input.value.trim();
        let isValid = true;
        let errorMessage = '';
        
        // Email validation
        if (input === emailInput) {
            const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
            if (!value) {
                errorMessage = 'Email address is required';
                isValid = false;
            } else if (!emailRegex.test(value)) {
                errorMessage = 'Please enter a valid email address';
                isValid = false;
            }
        }
        
        // Title validation
        else if (input === titleInput) {
            if (!value) {
                errorMessage = 'Artwork title is required';
                isValid = false;
            } else if (value.length < 3) {
                errorMessage = 'Title must be at least 3 characters';
                isValid = false;
            }
        }
        
        // Description validation
        else if (input === descriptionInput) {
            if (!value) {
                errorMessage = 'Description is required';
                isValid = false;
            } else if (value.length < 10) {
                errorMessage = 'Description must be at least 10 characters';
                isValid = false;
            }
        }
        
        // Tags validation
        else if (input === tagsInput) {
            if (activeTags.length === 0 && !value) {
                errorMessage = 'At least one tag is required';
                isValid = false;
            }
        }
        
        // Show error if invalid
        if (!isValid) {
            showError(input, errorMessage);
        } else {
            clearError(input);
        }
        
        return isValid;
    }
    
    function showError(input, message) {
        if (!input) return;
        
        let errorElement;
        
        if (input === aiRadios[0]) {
            // Special case for radio buttons
            errorElement = document.getElementById('ai-generated-error');
            if (errorElement) {
                errorElement.textContent = message;
                errorElement.style.display = 'block';
            }
        } else {
            // For regular inputs
            input.classList.add('error-input');
            errorElement = document.getElementById(`${input.id}-error`);
            
            if (errorElement) {
                errorElement.textContent = message;
                errorElement.style.display = 'block';
            }
        }
    }
    
    function clearError(input) {
        if (!input) return;
        
        if (input === aiRadios[0]) {
            // Clear radio button error
            const errorElement = document.getElementById('ai-generated-error');
            if (errorElement) {
                errorElement.textContent = '';
                errorElement.style.display = 'none';
            }
        } else {
            // Clear regular input error
            input.classList.remove('error-input');
            const errorElement = document.getElementById(`${input.id}-error`);
            
            if (errorElement) {
                errorElement.textContent = '';
                errorElement.style.display = 'none';
            }
        }
    }
    
    function resetErrors() {
        const errorMessages = document.querySelectorAll('.error-message');
        const errorInputs = document.querySelectorAll('.error-input');
        
        errorMessages.forEach(e => { e.textContent = ''; e.style.display = 'none'; });
        errorInputs.forEach(e => { e.classList.remove('error-input'); });
        
        formMessage.style.display = 'none';
        formMessage.textContent = '';
        formMessage.classList.remove('error', 'success');
    }
    
    function showFormMessage(message, type) {
        formMessage.textContent = message;
        formMessage.classList.add(type);
        formMessage.style.display = 'block';
    }
    
    // Tag handling functions
    function handleTagInput(e) {
        if (e.key === 'Enter' || e.key === ',') {
            e.preventDefault();
            addTag();
        } else if (e.key === 'Backspace' && tagInput.value === '' && activeTags.length > 0) {
            removeTag(activeTags.length - 1);
        }
    }
    
    function addTag() {
        const value = tagInput.value.trim().replace(/,/g, '');
        if (value && !activeTags.includes(value)) {
            activeTags.push(value);
            renderTags();
            tagInput.value = '';
            validateInput(tagInput);
        }
    }
    
    function removeTag(index) {
        activeTags.splice(index, 1);
        renderTags();
        validateInput(tagInput);
    }
    
    function renderTags() {
        tagContainer.innerHTML = '';
        
        activeTags.forEach((tag, index) => {
            const tagElement = document.createElement('span');
            tagElement.className = 'tag-item';
            tagElement.innerHTML = `${tag} <span class="tag-remove">×</span>`;
            
            const removeBtn = tagElement.querySelector('.tag-remove');
            removeBtn.addEventListener('click', () => removeTag(index));
            
            tagContainer.appendChild(tagElement);
        });
    }
    
    function resetTagContainer() {
        activeTags = [];
        renderTags();
    }
    
    function showTagSuggestions() {
        const value = tagInput.value.trim().toLowerCase();
        
        // If there's input, filter suggestions
        let matchedSuggestions = suggestions.filter(suggestion => 
            suggestion.toLowerCase().includes(value) && 
            !activeTags.includes(suggestion)
        );
        
        // Only show suggestions if there's input or we have tags to offer
        if ((value || activeTags.length < suggestions.length) && matchedSuggestions.length > 0) {
            // Display up to 5 suggestions
            matchedSuggestions = matchedSuggestions.slice(0, 5);
            
            tagSuggestions.innerHTML = '';
            matchedSuggestions.forEach(suggestion => {
                const item = document.createElement('div');
                item.className = 'tag-suggestion';
                item.textContent = suggestion;
                
                item.addEventListener('mousedown', function(e) {
                    // Prevent the input's blur event from firing and hiding suggestions
                    e.preventDefault();
                    
                    // Add the tag and clear input
                    activeTags.push(suggestion);
                    renderTags();
                    tagInput.value = '';
                    
                    // Hide suggestions after selection
                    tagSuggestions.style.display = 'none';
                    
                    // Set focus back to the input
                    setTimeout(() => {
                        tagInput.focus();
                    }, 10);
                });
                
                tagSuggestions.appendChild(item);
            });
            
            // Show suggestions and adjust positioning
            tagSuggestions.style.display = 'block';
            
            // Position suggestions appropriately
            positionTagSuggestions();
            
            // Adjust the position of elements below
            adjustPositioning();
        } else {
            tagSuggestions.style.display = 'none';
            
            // When hiding, reset element positions
            tagSuggestions.style.position = 'absolute';
            adjustPositioning();
        }
    }
    
    function positionTagSuggestions() {
        // Get element positions
        const inputRect = tagInput.getBoundingClientRect();
        const containerRect = tagContainer.getBoundingClientRect();
        
        // Position below the input
        tagSuggestions.style.position = 'relative';
        tagSuggestions.style.width = inputRect.width + 'px';
        tagSuggestions.style.marginTop = '5px';
        tagSuggestions.style.marginBottom = '15px';
        tagSuggestions.style.zIndex = '100';
    }
    
    function adjustPositioning() {
        // Get the file upload group
        const fileUploadGroup = document.querySelector('.file-upload');
        
        // If suggestions are visible, add some margin to the file upload group
        if (tagSuggestions.style.display === 'block') {
            fileUploadGroup.style.marginTop = 5 + 'px';
        } else {
            // Reset margin when suggestions are hidden
            fileUploadGroup.style.marginTop = '0';
        }
    }
    
    // Initialize with empty tag container
    renderTags();
});
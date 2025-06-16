# 📄 Picverse Project Documentation

**Figma Prototype:**  
🔗 [View on Figma](https://www.figma.com/proto/hh9r4xsTKc5rgZUwpA1VC5/Picverse?node-id=0-1&t=aXzCxlhR3klaV5MQ-1)

---

## 📚 Table of Contents

- [Header](#header)
- [Footer](#footer)
- [Pages](#pages)
  - [Home](#home)
  - [Gallery](#gallery)
  - [Submission](#submission)
  - [Community](#community)
  - [About Us](#about-us)
- [Assets & Image Sources](#assets--image-sources)
- [Color Palette Inspiration](#color-palette-inspiration)

---

## 🧭 Header

- The logo at the top-left serves as a shortcut to the homepage. Clicking it returns users to the main page, ensuring smooth and intuitive navigation.
- The top navigation bar features horizontally aligned menu items. Each link directs users to a corresponding section, with active links visually indicated by color changes.
- On tablets and mobile devices, the navigation bar transforms into a hamburger menu for better responsiveness and a cleaner interface.
- The Login and Signup buttons currently function as placeholders that redirect back to the homepage.

---

## 🦶 Footer

- All navigation items in the footer are interactive, redirecting users to their respective pages for consistent navigation.
- The "Resources" and "Connect" sections are visual placeholders for now, redirecting to the homepage.

---

## 📄 Pages

### 🏠 Home

#### 🖼️ Carousel
- Arrows are positioned at the bottom center for slide navigation.
- Dots between the arrows indicate which slide is currently active.
- Clicking a dot jumps directly to the respective slide.
- A “Explore Gallery” button links directly to the Gallery page.

#### 🔥 Trending Tags
- Each tag acts as a filter link that leads to the Gallery page.
- If the tag has no content, it still redirects to the general gallery page as fallback.
- Tags are limited to 10 and centered on the screen for visual balance.

#### 🎨 Featured Artwork
- Displays a randomized gallery of featured artworks.
- Clicking an image opens a dynamic overlay with additional details.

#### 🧊 Overlay
- Overlay content is fetched from a JSON structure and displayed dynamically.
- The “X” button (top-right) closes the overlay and supports both click and Esc key.
- Action buttons like Like, Comment, Share are placeholders with hover animations.

---

### 🖼️ Gallery

#### 🎯 Hero Section
- A large headline with a short subheading is displayed prominently.

#### 🏷️ Tags
- Up to 20 tags are displayed; extra tags can be accessed via a “More” button (not fully implemented yet).
- Tags are aligned to the left to differentiate from the centered layout on the Home page.
- Accessibility is considered: keyboard navigation and screen reader support are implemented.

#### 📁 Tag Sections
- Example tags: `#DigitalArt`, `#ConceptPainting`, `#PixelArt`
- Clicking a tag scrolls to its corresponding content block.
- Overlay popup behavior is the same as on the Home page.

---

... *(and so on for the rest: Submission, Community, About Us)*

---

## 🖼️ Assets & Image Sources

List of image sources used in mockups:
- [Billboard](https://www.billboard.com/lists/best-kpop-albums-songs-2022/)
- [Wikipedia - Karina Aespa](https://zh.wikipedia.org/wiki/File:Karina_for_Eternal_Return_%C3%97_aespa_collaboration_BTS_photoshoot_03.jpg)
- [TikTok - Katrina Irene](https://www.tiktok.com/discover/katrina-irene-jkt48)
- ... *(etc. — can be shortened or numbered if needed)*

---

## 🌈 Color Palette Inspiration

The color palette was inspired by a friend’s motorcycle BILED light — a bright mix of neon blue and purple that’s both striking and slightly eye-burning. These colors were adjusted for digital use to maintain that bold neon aesthetic while keeping it visually pleasant.

> Design references:
> - [Dribbble](https://dribbble.com)
> - [Behance](https://www.behance.net)

---

## ✅ Final Notes

> This documentation describes a mock-up interface with static, gimmick-driven interactions. No backend functionality is implemented yet, but the design anticipates future scalability.

---


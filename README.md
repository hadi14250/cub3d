# Cub3d

<div align="center">
<a href="https://github.com/hadi14250">
    <img src="github_gifs/cub-rounded.gif" alt="Logo" width="150" height="150">
  </a>
  <h3 align="center">Cub3D</h3>
  3D Game Inspired By Doom
  <br>
  <br>
</div>


<br>


# Cub3D

Inspired by Doom, the first game that introduced ray casting. We start with displaying a single pixel on the screen to drawing complex 3d structures. Uses the simple 42 C graphics library called MLX. 

<br>

## Distinctive Features

  - 🎯 Aiming (zooming in).
  - 🧱 Wall collision.
  - 🗺️ Minimap, can be minimised and maximised.
  - 🔎 Minimap shows player feild of view.
  - 🖱️ Mouse movement (event listener).

<br>

## How to play

- Go to root directory and run `make`
- Run ```docker-compose up --build```
- Go to ```https://localhost:80/```
- Authorise With 42 Intra
- Enjoy

<br>


## Usage
```javascript
import copyCodeBlock from '@pickra/copy-code-block';
// OR
const copyCodeBlock = require('@pickra/copy-code-block');
```
Then add it to your code
```javascript
import anHtmlFile from './anHtmlFile.html';
copyCodeBlock(anHtmlFile);
```
OR
```javascript
copyCodeBlock('<div>Thundercats</div>')
```
OR
```javascript
`${copyCodeBlock('<div>Thundercats</div>')}`
```
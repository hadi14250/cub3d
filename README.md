<div align="center">
  <a href="https://github.com/hadi14250">
    <img src="github_gifs/cub-rounded.gif" alt="3d cube" width="150" height="150">
  </a>

  <h1>Cub3D</h1>

  <p><strong>A 3D game inspired by Doom — built from scratch in C using ray casting.</strong></p>
</div>

<br>

<div align="center">
  <a href="https://github.com/hadi14250">
    <img src="github_gifs/gameplay.gif" alt="gameplay" width="600" height="400">
  </a>
</div>

<br>

## About

Cub3D is a 42 project inspired by Doom, the first game to popularize ray casting. The journey starts at drawing a single pixel and grows into rendering complex 3D scenes in real time. The renderer is built on top of the minimal 42 C graphics library, **MLX**.

<br>

## Features

- 🎯 **Aiming** — zoom in for a closer shot
- 🧱 **Wall collision** detection
- 🗺️ **Minimap** with minimize and maximize support
- 🔎 **Field-of-view rays** drawn on the minimap
- 🖱️ **Mouse look** via event listener
- 🎮 **In-game controls panel** with clickable buttons
- 🎨 **Customization on the fly** — change ray color, equip/un-equip the gun, reset controls

<br>

## Getting Started

```sh
make
./cub3d maps/good/bigmap.cub
```

Other maps are available in `maps/good/`.

<br>

## Controls

### Keyboard

| Key | Action |
| --- | --- |
| `W` `A` `S` `D` | Move the player |
| `←` `→` / mouse | Look around |
| `Shift` | Aim (zoom) |
| `C` | Open / close controls menu |
| `F` | Maximize / minimize minimap |
| `Q` | Show / hide minimap |
| `Esc` | Quit |

### Controls Menu

- Randomize the minimap ray color
- Equip or un-equip the gun
- Reset controls back to defaults

<br>

## Built With

- **C**
- **MLX** — the 42 graphics library
- **Makefile** build system
- A custom **libft** for core utilities

<br>

<div align="center">
  <sub>Made as part of the 42 curriculum.</sub>
</div>

# storefront-lights
Arudino code for driving pixel strips for Sam Trout's October 2018 storefront installation.

## Repository branching strategy
* master: only for production code, always guaranteed to work
* develop: mostly-working code, but sometimes won't work.
* feature/my_feature: completely bleeding edge, no guarantees

## Reposity structure
* ./arduino: most of the code
* ./images: project images
* ./documents: documentation and notes

## Key files
* ./arduion/storefront.ino: main arduino sketch for storefront
* ./arduion/packmatrix.ino: reference arduino sketch from backpack lights

# Initial Plan (9/13/18)
There will be one set of pixel strips wired together as a continuous line working in two banks, where the split point will be configurable.
* Bank 1: up against the window, this bank will have a slowly moving set of centroids, each of which will have a distribution of lights
around it, glowing and receding at its own pace. The overall set of these will be modulated by a slower moving wave.
* Bank 2: between the window objects and the trash wave, these lights will brighten as the first bank darkens, reaching a high brightness
with some random flashes. These may be of a red-orange tone to make it more ominous.

This sketch shows a prototype box and the rough time characteristic of the banks and patterns:

<img src="./docs/180913_initial_plan_diagram.jpg" style="width: 800px;"/>

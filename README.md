<p align="center"> 
 <img src="assets/main_image.png" alt="Rubiks_cube_2" width="150">
</p>

<h1 align="center"> Rubik's Cube Solver </h1>

<p align="center">
  <img src="assets/rainbow.png"" alt="Rainbow" width="your_preferred_width">
</p>

<!-- TABLE OF CONTENTS -->
<h2 id="table-of-contents"> :book: Table of Contents</h2>

<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project"> ➤ About The Project</a></li>
    <li><a href="#overview"> ➤ Overview</a></li>
    <li><a href="#project-files-description"> ➤ Project Files Description</a></li>
    <li><a href="#getting-started"> ➤ Getting Started</a></li>
    <li><a href="#step1"> ➤ Step 1: Solving The White Cross </a></li>
    <li><a href="#step2"> ➤ Step 2: Solving The First Layer </a></li>
    <li><a href="#step3"> ➤ Step 3: Solving The White Crossh </a></li>
    <li><a href="#step4"> ➤ Step 4: Solving The White Cross </a></li>
    <li><a href="#step5"> ➤ Step 5: Solving The White Cross </a></li>
    <li><a href="#step6"> ➤ Step 6: Solving The White Cross </a></li>
    <li><a href="#step7"> ➤ Step 7: Solving The White Crosss </a></li>
    <li><a href="#step8"> ➤ Step 8: Solving The White Cross </a></li>
    <li><a href="#references"> ➤ References</a></li>
    <li><a href="#credits"> ➤ Credits</a></li>
  </ol>
</details>

<p align="center">
  <img src="assets/rainbow.png"" alt="Rainbow" width="your_preferred_width">
</p>

<!-- ABOUT THE PROJECT -->
<h2 id="about-the-project"> :pencil: About The Project</h2>

<p align="justify"> 
  If you're new to Rubik's Cube solving, let's dive into it. The Rubik's Cube Solver is a tool designed to crack the challenge posed by the iconic Rubik's Cube. This six-sided puzzle features individual colored squares on each face, and the objective is to rearrange these colors until each face exhibits a uniform hue.
</p>

<p align="center">
  <img src="assets/rainbow.png"" alt="Rainbow" width="your_preferred_width">
</p>

<!-- OVERVIEW -->
<h2 id="overview"> :cloud: Overview</h2>

<p align="justify"> 
  The solver strategically manipulates the cube through a series of rotations, solving one layer at a time. Think of it as deciphering a complex code, where each twist and turn is a step toward the ultimate goal, achieving a perfectly solved Rubik's Cube.

  Completing the Rubik's Cube is a triumph of logic and problem-solving. The solver engages in a dance of twists and rotations, overcoming challenges until all colors align harmoniously on each face. It's a satisfying journey that culminates in the visual delight of a perfectly solved Rubik's Cube.
</p>

<p align="center">
  <img src="assets/rainbow.png"" alt="Rainbow" width="your_preferred_width">
</p>

<!-- STEP1 -->
<h2 id="step1"> :small_orange_diamond: Step 1: Solving The White Cross</h2>

<p>The solveWhiteCross method is responsible for solving the white cross on the Rubik's Cube. It employs a step-by-step approach, considering the orientation and placement of white edge pieces in different positions on the cube faces. The function uses various algorithms to manipulate the cube and achieve the desired white cross configuration.</p>
<h3>🧠Algorithm Explanation</h3>
<p>The function first initializes variables to track the state of each edge piece and the overall progress of the white cross. It then checks each edge piece on the bottom face (denoted as 'w') against the adjacent face's center color (e.g., front, left, right, back). If an edge piece is correctly positioned, it increments the count of correct white edge pieces.</p>
<p>If an edge piece is not in the correct position, the function executes specific cube rotations (e.g., F, B, R, L) to align the pieces correctly. The process continues until all white edge pieces are correctly positioned.</p>
<p>The function also considers edge pieces on the second layer and performs appropriate rotations to solve those as well.</p>
<p>After successfully solving the white cross, the function prints a success message.</p>

<p align="center">
  <img src="assets/whiteCross.png"" alt="cubeImage" width="150">
</p>

<p align="center">
  <img src="assets/rainbow.png"" alt="Rainbow" width="your_preferred_width">
</p>

<!-- STEP2 -->
<h2 id="step2"> :small_orange_diamond: Step 2: Solving The First Layer</h2>

<p>The solveFirstLayer method in the Rubik's Cube solver is responsible for solving the first layer of the cube, which involves correctly placing and orienting the white corner pieces. The method utilizes a step-by-step approach, considering the current state of each corner piece and performing specific algorithms to achieve the desired configuration.</p>
<p>The Pacman will quickly find a solution via running the following commands:</p>
<h3>🧠Algorithm Explanation</h3>
<p>The function starts by checking the initial state of each white corner piece, tracking the progress of the first layer solution. It identifies the corners in the top-left, top-right, bottom-left, and bottom-right positions, determining whether they are correctly placed and oriented.</p>
<p>If a corner is not in the correct position, the function executes a series of cube rotations (e.g., R, L, U, D) along with their inverses to adjust the corner pieces. The process continues until all white corner pieces are correctly placed and oriented.</p>
<p>The algorithm accounts for various scenarios, including different positions of white corners in the first layer. It utilizes specific sequences of cube rotations to achieve the desired configuration for each corner.</p>
<p>If there are white pieces in the third layer, the function adjusts their positions by turning the U face or U' face and checking for correct placements. If needed, it backtracks by turning U or U' again until the correct configuration is achieved.</p>
<p>After successfully solving the first layer, the function prints a success message.</p>

<p align="center">
  <img src="assets/firstLayerSolved.png"" alt="cubeImage" width="150">
</p>

<p align="center">
  <img src="assets/rainbow.png"" alt="Rainbow" width="your_preferred_width">
</p>

<!-- STEP3 -->
<h2 id="step3"> :small_orange_diamond: Step 3: Solving The Second Layer</h2>
<p>The solveSecondLayer method in the Rubik's Cube solver focuses on solving the second layer of the cube. This involves correctly placing and orienting the edge pieces with two colors (not including white) to complete the first two layers of the cube.</p>
<p>The function uses a step-by-step approach, checking the initial state of each edge piece in the second layer and tracking the progress of the solution. It employs specific algorithms to adjust the positions of the edge pieces until the entire second layer is solved.</p>
<h3>🧠Algorithm Explanation</h3>
<p>The function begins by checking each edge piece in the second layer and counting the number of correctly positioned pieces. If an edge piece is already in the correct position, it increments the count of correct pieces.</p>
<p>If an edge piece is not in the correct position, the function executes specific cube rotations based on the relative positions of the edge piece and the white stickers in the first layer. It considers different scenarios for each side of the cube (front, back, left, right) and makes appropriate adjustments.</p>
<p>The function also handles cases where there is a "correct piece in the wrong position." In such situations, it performs necessary cube rotations to bring the edge piece to the correct position.</p>
<p>If any adjustments are made, the function increments the count of correct pieces and continues the process until all edge pieces in the second layer are correctly positioned.</p>
<p>After successfully solving the second layer, the function prints a success message.</p>

<p align="center">
  <img src="assets/secondLayerSolved.png"" alt="cubeImage" width="150">
</p>

<p align="center">
  <img src="assets/rainbow.png"" alt="Rainbow" width="your_preferred_width">
</p>

<!-- STEP4 -->
<h2 id="step4"> :small_orange_diamond: Step 4: Solving The Yellow Cross</h2>

<p>The solveYellowCross method in the Rubik's Cube solver is designed to solve the yellow cross on the cube. It employs specific algorithms and moves to manipulate the cube's state and achieve the desired yellow cross configuration on the top face.</p>
<h3>🧠Algorithm Explanation</h3>
<p>The function checks the current state of yellow stickers on the top face and executes various algorithms based on their arrangement. The goal is to create a yellow cross, handling scenarios with two, three, or four yellow stickers in specific positions.</p>
<p>If the yellow cross is already solved, the function exits with a success message. Otherwise, it performs moves like <code>F U R U' R' F'</code> to ensure at least two yellow stickers are on top. It then adapts its approach based on the specific arrangement of yellow stickers.</p>
<p>If successful, the function prints a success message.</p>

<p align="center">
  <img src="assets/yellowCross.png"" alt="cubeImage" width="150">
</p>

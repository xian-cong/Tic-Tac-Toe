# Tic Tac Toe
Game developed with C language. There are 3 modes for this game:
- Player vs Player
- Player vs Smart AI Computer
- Player vs Random AI Computer

## To Play
Code is developed in Linux and compiled using **gcc**. To run the code, compile and run in **Terminal** with:
```
gcc PlayerVsComputer.c && ./a.out
```

## Smart AI
Algoritm used for Smart AI is **reactive planning algorithm**:
1. If the computer can immediately win on its current move, it will play the winning move and ends the game.
2. If the opponent is about to win on the next move, it can block the opponents’ winning move.
3. If neither above 2 scenarios occurs, the computer falls back to the random AI.

## Player vs Player
Players takes turn to play as shown below.
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149460966-bc26b204-f83d-43d4-9130-cbc96cca1b60.png" width="500"> </br>
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149461011-f87302e4-72fa-42a5-b422-0f5169f87f15.png" width="500"> </br>
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149461032-a8642240-23f8-4e63-9026-71cb95347808.png" width="500"> </br>

## Player vs Computer
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149461078-f7259763-9973-4461-90a5-2bc1e8dccaf2.png" width="500"> </br>

### Player vs Smart AI
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149461122-1df76215-2b09-4306-9665-b41e1e9b477c.png" width="500"> </br>
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149461141-32286d3c-b332-416c-8bfa-7e6acaee007d.png" width="500"> </br>

### Player vs Random AI
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149461227-c8f0327d-18ce-4c6e-b66c-955ce1f41c12.png" width="500"> </br>
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149461241-aa2faa12-0b42-474f-ad96-7c3ec4637f07.png" width="500"> </br>

## Result of AI vs AI
Since the AI does not have strategies to win as it only plays based on conditions, the AI will not always win/draw. Hence, the result of the AI vs AI is shown below:
<h4 align="center"> <img src="https://user-images.githubusercontent.com/22144223/149460184-4e454b02-8d3d-4b23-9466-9bc4f4d43caa.png" width="500"> </br>

## Additional Information
Additional information about the research can be found [here](https://github.com/xian-cong/Tic-Tac-Toe/blob/main/Report.pdf)

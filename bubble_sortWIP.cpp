for (int j = 0; j < 20; j++){

			for (int i = 0; i < numPlayers - 1; i++){
				
				Player *sortingArray = new Player[2];
				sortingArray[0] = players[i];
				sortingArray[1] = players[i + 1];
				if (sortingArray[0].getScore() > sortingArray[1].getScore()){
					players[i] = sortingArray[0];
					players[i + 1] = sortingArray[1];
				}
				else if (sortingArray[0].getScore() < sortingArray[1].getScore()){
					players[i] = sortingArray[1];
					players[i + 1] = sortingArray[0];
				}
				else if (sortingArray[0].getScore() == sortingArray[1].getScore()){
					continue;
				}
				delete[] sortingArray;
			}
			if (numPlayers == 1){
				if (players[numPlayers - 1].getScore() < players[numPlayers].getScore()){
					Player *sortingArray = new Player[2];
					sortingArray[0] = players[numPlayers - 1];
					sortingArray[1] = players[numPlayers	];
					players[numPlayers - 1] = sortingArray[1];
					players[numPlayers] = sortingArray[0];
					delete[] sortingArray;
				}
				else{
					continue;
				}
			}	
		}
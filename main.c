#include <stdio.h>

int table[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
int ask_change_pos(char who, int* player_X, int* player_Y);
int check_win();
int display_table();

int main() {
	char check;
	display_table();
	while (1) {
		int player_A_X, player_A_Y;
		ask_change_pos('A', &player_A_X, &player_A_Y);
		check = check_win();
		if (check == 'A') {
			printf("勝者はplayer%cです", check);
			break;
		}

		int player_B_X, player_B_Y;
		ask_change_pos('B', &player_B_X, &player_B_Y);
		check = check_win();
		if (check == 'B') {
			printf("勝者はplayer%cです", check);
			break;
		}
	}
	return 0;
}

int ask_change_pos(char who, int* player_X, int* player_Y) {
	while (1) {
		printf("player%cはX座標を指定してください\n", who);
		scanf_s("%d", &*player_X);
		printf("player%cはY座標を指定してください\n", who);
		scanf_s("%d", &*player_Y);
		if (*player_X < 1 || *player_X > 3 || *player_Y < 1 || *player_Y > 3) {
			printf("そのような座標はありません\n");
			continue;
		}
		else {
			*player_X = *player_X - 1;
			*player_Y = *player_Y - 1;
			if (table[*player_Y][*player_X] == 1 || table[*player_Y][*player_X] == 2) {
				printf("その座標はすでに取得されています");
				continue;
			}
			break;
		}
	}
	if (who == 'A') {
		table[*player_Y][*player_X] = 1;
	}
	else if (who == 'B') {
		table[*player_Y][*player_X] = 2;
	}
	display_table();
	return 0;
}

int check_win() {
	for (int i = 0; i < 3; i++) {
		if (table[i][0] == 1 && table[i][1] == 1 && table[i][2] == 1) {
			return 'A';
		}
		else if (table[i][0] && 2 && table[i][1] == 2 && table[i][2] == 2) {
			return 'B';
		}
		if (table[0][i] == 1 && table[1][i] == 1 && table[2][i] == 1) {
			return 'A';
		}
		else if (table[0][i] == 2 && table[1][i] == 2 && table[2][i] == 2) {
			return 'B';
		}
	}
	if (table[0][0] == 1 && table[1][1] == 1 && table[2][2] == 1) {
		return 'A';
	}
	else if (table[0][0] == 2 && table[1][1] == 2 && table[2][2] == 2) {
		return 'B';
	}

	if (table[2][0] == 1 && table[1][1] == 1 && table[0][2] == 1) {
		return 'A';
	}
	else if (table[2][0] == 2 && table[1][1] == 2 && table[0][2] == 2) {
		return 'B';
	}
	return 0;
}

int display_table() {
	for (int i = 0; i < 3; i++) {
		printf("-------------\n");
		printf("|   |   |   |\n");
		printf("| %d | %d | %d |\n", table[i][0], table[i][1], table[i][2]);
		printf("|   |   |   |\n");
	}
	printf("-------------\n\n");
	return 0;
}
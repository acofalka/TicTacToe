#pragma once

enum FIELD {
	F_EMPTY,
	F_CIRCLE = 'O',
	F_CROSS = 'X'
};

enum SIGN {
	S_CIRCLE = F_CIRCLE,
	S_CROSS = F_CROSS
};

enum GAMESTATE {
	NOTSTARTED,
	MOVE,
	WIN,
	DRAW
};
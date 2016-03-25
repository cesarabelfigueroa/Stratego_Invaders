productions: space_invaders stratego clean

space_invaders: space_invaders.o
	g++ space_invaders.o -o productions/space_invaders/space_invaders $(`pkg-config --libs allegro-5.0`) -lallegro -lallegro_ttf  -lallegro_primitives -lallegro_main -lallegro_font -lallegro_image -lallegro_audio -lallegro_acodec

space_invaders.o:	core/space_invaders/space_invaders.cpp 
	g++ -c core/space_invaders/space_invaders.cpp 

stratego: stratego.o marshal.o token.o general.o coronel.o commander.o captain.o lieutenant.o sergeant.o minelayer.o explorer.o spy.o bomb.o flag.o lake.o
	g++ stratego.o marshal.o token.o general.o coronel.o commander.o captain.o lieutenant.o sergeant.o minelayer.o explorer.o spy.o bomb.o flag.o lake.o -o productions/stratego/stratego $(`pkg-config --libs allegro-5.0`) -lallegro -lallegro_ttf  -lallegro_primitives -lallegro_main -lallegro_font -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_dialog 

stratego.o: core/stratego/stratego.cpp core/stratego/tokens/token.h core/stratego/tokens/marshal.h core/stratego/tokens/general.h core/stratego/tokens/coronel.h core/stratego/tokens/commander.h core/stratego/tokens/captain.h core/stratego/tokens/lieutenant.h core/stratego/tokens/sergeant.h core/stratego/tokens/minelayer.h core/stratego/tokens/explorer.h core/stratego/tokens/spy.h core/stratego/tokens/bomb.h core/stratego/tokens/flag.h
	g++ -c core/stratego/stratego.cpp

token.o: core/stratego/tokens/token.h core/stratego/tokens/token.cpp
	g++ -c core/stratego/tokens/token.cpp

marshal.o: core/stratego/tokens/token.h  core/stratego/tokens/marshal.h  core/stratego/tokens/marshal.cpp
	g++ -c core/stratego/tokens/marshal.cpp

general.o: core/stratego/tokens/token.h core/stratego/tokens/general.h core/stratego/tokens/general.cpp
	g++ -c core/stratego/tokens/general.cpp

coronel.o: core/stratego/tokens/token.h core/stratego/tokens/coronel.h core/stratego/tokens/coronel.cpp
	g++ -c core/stratego/tokens/coronel.cpp

commander.o: core/stratego/tokens/token.h core/stratego/tokens/commander.h core/stratego/tokens/commander.cpp
	g++ -c core/stratego/tokens/commander.cpp

captain.o: core/stratego/tokens/token.h core/stratego/tokens/captain.h core/stratego/tokens/captain.cpp
	g++ -c core/stratego/tokens/captain.cpp

lieutenant.o: core/stratego/tokens/token.h core/stratego/tokens/lieutenant.h core/stratego/tokens/lieutenant.cpp
	g++ -c core/stratego/tokens/lieutenant.cpp

sergeant.o: core/stratego/tokens/token.h core/stratego/tokens/sergeant.h core/stratego/tokens/sergeant.cpp
	g++ -c core/stratego/tokens/sergeant.cpp

minelayer.o: core/stratego/tokens/token.h core/stratego/tokens/minelayer.h core/stratego/tokens/minelayer.cpp
	g++ -c core/stratego/tokens/minelayer.cpp

explorer.o: core/stratego/tokens/token.h core/stratego/tokens/explorer.h core/stratego/tokens/explorer.cpp
	g++ -c core/stratego/tokens/explorer.cpp

spy.o: core/stratego/tokens/token.h core/stratego/tokens/spy.h core/stratego/tokens/spy.cpp
	g++ -c core/stratego/tokens/spy.cpp

bomb.o: core/stratego/tokens/token.h core/stratego/tokens/bomb.h core/stratego/tokens/bomb.cpp
	g++ -c core/stratego/tokens/bomb.cpp

flag.o: core/stratego/tokens/token.h core/stratego/tokens/flag.h core/stratego/tokens/flag.cpp
	g++ -c core/stratego/tokens/flag.cpp

lake.o: core/stratego/tokens/token.h core/stratego/tokens/lake.h core/stratego/tokens/lake.cpp
	g++ -c core/stratego/tokens/lake.cpp
clean: 
	rm *.o



productions: space_invaders stratego clean

space_invaders: space_invaders.o
	g++ space_invaders.o -o productions/space_invaders/main.exe `pkg-config --libs allegro-5.0` -lallegro -lallegro_ttf  -lallegro_primitives -lallegro_main -lallegro_font -lallegro_image -lallegro_audio -lallegro_acodec

space_invaders.o:	core/space_invaders/space_invaders.cpp 
	g++ -c core/space_invaders/space_invaders.cpp 

stratego: stratego.o marshal.o token.o general.o coronel.o commander.o captain.o lieutenant.o sergeant.o minelayer.o explorer.o spy.o bomb.o flag.o
	g++ stratego.o marshal.o token.o general.o coronel.o commander.o captain.o lieutenant.o sergeant.o minelayer.o explorer.o spy.o bomb.o flag.o -o productions/stratego/stratego

stratego.o: core/stratego/stratego.cpp core/stratego/token.h core/stratego/marshal.h
	g++ -c core/stratego/stratego.cpp

token.o: core/stratego/token.h core/stratego/token.cpp
	g++ -c core/stratego/token.cpp

marshal.o: core/stratego/token.h  core/stratego/marshal.h  core/stratego/marshal.cpp
	g++ -c core/stratego/marshal.cpp

general.o: core/stratego/token.h core/stratego/general.h core/stratego/general.cpp
	g++ -c core/stratego/general.cpp

coronel.o: core/stratego/token.h core/stratego/coronel.h core/stratego/coronel.cpp
	g++ -c core/stratego/coronel.cpp

commander.o: core/stratego/token.h core/stratego/commander.h core/stratego/commander.cpp
	g++ -c core/stratego/commander.cpp

captain.o: core/stratego/token.h core/stratego/captain.h core/stratego/captain.cpp
	g++ -c core/stratego/captain.cpp

lieutenant.o: core/stratego/token.h core/stratego/lieutenant.h core/stratego/lieutenant.cpp
	g++ -c core/stratego/lieutenant.cpp

sergeant.o: core/stratego/token.h core/stratego/sergeant.h core/stratego/sergeant.cpp
	g++ -c core/stratego/sergeant.cpp

minelayer.o: core/stratego/token.h core/stratego/minelayer.h core/stratego/minelayer.cpp
	g++ -c core/stratego/minelayer.cpp

explorer.o: core/stratego/token.h core/stratego/explorer.h core/stratego/explorer.cpp
	g++ -c core/stratego/explorer.cpp

spy.o: core/stratego/token.h core/stratego/spy.h core/stratego/spy.cpp
	g++ -c core/stratego/spy.cpp

bomb.o: core/stratego/token.h core/stratego/bomb.h core/stratego/bomb.cpp
	g++ -c core/stratego/bomb.cpp

flag.o: core/stratego/token.h core/stratego/flag.h core/stratego/flag.cpp
	g++ -c core/stratego/flag.cpp

clean: 
	rm *.o

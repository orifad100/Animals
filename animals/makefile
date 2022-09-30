prog: Animal.o Chicken.o ChickenFarm.o Cow.o CowFarm.o Farm.o farmMarket.o Market.o Sheep.o SheepFarm.o 
	g++ -g Animal.o Chicken.o ChickenFarm.o Cow.o CowFarm.o Farm.o farmMarket.o Market.o Sheep.o SheepFarm.o  -o CPP_FARM
Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp -g
Chicken.o: Chicken.cpp Chicken.h Animal.h
	g++ -c Chicken.cpp -g
ChickenFarm.o: ChickenFarm.cpp ChickenFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h
	g++ -c ChickenFarm.cpp -g
Cow.o: Cow.cpp Cow.h Animal.h
	g++ -c Cow.cpp -g
CowFarm.o.o: CowFarm.cpp CowFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h
	g++ -c CowFarm.cpp -g
Farm.o: Farm.cpp Farm.h Animal.h Chicken.h Cow.h Sheep.h
	g++ -c Farm.cpp -g
farmMarket.o: farmMarket.cpp Market.h CowFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h ChickenFarm.h SheepFarm.h
	g++ -c farmMarket.cpp -g
Market.o: Market.cpp Market.h CowFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h ChickenFarm.h SheepFarm.h
	g++ -c Market.cpp -g
Sheep.o: Sheep.cpp Sheep.h Animal.h
	g++ -c Sheep.cpp -g
SheepFarm.o: SheepFarm.cpp SheepFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h
	g++ -c SheepFarm.cpp -g

clean:
	rm -f *.o

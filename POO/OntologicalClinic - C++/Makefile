all: ./O/pessoa.o ./O/admin.o ./O/dentista.o ./O/recepcionista.o ./O/agenda.o ./O/funcionario.o ./O/clinica.o ./O/cliente.o ./O/consulta.o ./O/contas.o ./O/userGeral.o main.cpp
	g++ -o ./O/main ./O/pessoa.o ./O/admin.o ./O/dentista.o ./O/recepcionista.o ./O/agenda.o ./O/funcionario.o ./O/clinica.o ./O/cliente.o ./O/consulta.o ./O/contas.o ./O/userGeral.o main.cpp -Wall

./O/pessoa.o: ./CPP/pessoa.cpp
	g++ -o ./O/pessoa.o -c ./CPP/pessoa.cpp

./O/consulta.o: ./CPP/consulta.cpp
	g++ -o ./O/consulta.o -c ./CPP/consulta.cpp

./O/admin.o: ./CPP/admin.cpp
	g++ -o ./O/admin.o -c ./CPP/admin.cpp

./O/dentista.o: ./CPP/dentista.cpp
	g++ -o ./O/dentista.o -c ./CPP/dentista.cpp

./O/recepcionista.o: ./CPP/recepcionista.cpp
	g++ -o ./O/recepcionista.o -c ./CPP/recepcionista.cpp

./O/agenda.o: ./CPP/agenda.cpp
	g++ -o ./O/agenda.o -c ./CPP/agenda.cpp

./O/funcionario.o: ./CPP/funcionario.cpp
	g++ -o ./O/funcionario.o -c ./CPP/funcionario.cpp

./O/clinica.o: ./CPP/clinica.cpp ./HPP/clinica.hpp
	g++ -o ./O/clinica.o -c ./CPP/clinica.cpp

./O/cliente.o: ./CPP/cliente.cpp
	g++ -o ./O/cliente.o -c ./CPP/cliente.cpp

./O/contas.o: ./CPP/contas.cpp
	g++ -o ./O/contas.o -c ./CPP/contas.cpp

./O/userGeral.o: ./CPP/userGeral.cpp
	g++ -o ./O/userGeral.o -c ./CPP/userGeral.cpp

clean:
	rm -f ./O/*.o ./O/main

run:
	./O/main


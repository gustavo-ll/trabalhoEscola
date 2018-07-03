#include <iostream>
#include <string>
#include <vector>
#include <conio2.h>
#include <fstream>

using namespace std;

#include "Notas.h"
#include "Disciplinas.h"
#include "Alunos.h"

#include "Notas.cpp"
#include "Disciplinas.cpp"
#include "Alunos.cpp"
//#include "Funcoes.cpp"

main()
{
	string opcao;
	
	Notas  minhasNotas;
//	Funcoes  meusFuncoes;
	Alunos meusAlunos(&minhasNotas);
	Disciplinas minhasDisciplinas(&minhasNotas);
	
	while (true)
	{
		textbackground(BLACK);
		clrscr();
		textcolor(YELLOW);
		gotoxy(1,1); cout << "Menu";
		textcolor(WHITE);
		gotoxy(1,2); cout << "1 - Manter Alunos";
		gotoxy(1,3); cout << "2 - Manter Disciplinas";
		gotoxy(1,4); cout << "3 - Manter Notas";
		gotoxy(1,5); cout << "4 - Imprimir Boletim";
		gotoxy(1,6); cout << "0 - Sair";
		gotoxy(1,7); cout << "Opcao : ";
		textcolor(LIGHTCYAN);
		opcao = getche();
		textcolor(WHITE);
		
		if (opcao == "0") break;
		
		if (opcao == "1") meusAlunos.executarCRUD();
		
		if (opcao == "2") minhasDisciplinas.executarCRUD();
		
		if (opcao == "3") minhasNotas.executarCRUD(); 
	
	//	if (opcao == "4") meusFuncoes.montarMoldura(10,5,70,30,true);
	
	
		
	}
	clrscr();
}


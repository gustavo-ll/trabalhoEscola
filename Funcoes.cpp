
Funcoes::Funcoes(Notas *enderecoNotas, Disciplinas *enderecoDisciplinas, Alunos *enderecoAlunos)
	{
	
	this->enderecoNotas=enderecoNotas;
	this->enderecoDisciplinas=enderecoDisciplinas;
	this->enderecoAlunos=enderecoAlunos;
	
	}
	
void Funcoes::limparArea(int colini, int linini, int colfim, int linfim)
	{
		int coluna, linha;
		for (coluna=colini; coluna<=colfim; coluna++)
		{
			for(linha=linini; linha<=linfim; linha++)
			{
				gotoxy(coluna, linha);
				cout<<" ";
			}
		}
	}

void Funcoes::montarMoldura(int colini, int linini, int colfim , int linfim)
{
	int x;
	
	linfim=this->enderecoNotas->vCodigosN.size()+1;
	
	clrscr();
	
	int coluna, linha;
	
	limparArea(colini, linini, colfim, linfim);
	
	for(coluna=colini; coluna<=colfim; coluna++)
	{
		gotoxy(coluna, linini); cout<< char(205);
		gotoxy(coluna, linfim); cout<< char(205);
	}
	
	gotoxy(2,1); cout << "Aluno:";
	for (x=0; x<this->enderecoAlunos->vCodigos.size(); x++)
	{
			gotoxy(10,x+1); cout << this->enderecoAlunos->vNomes[x];
	}
	
	gotoxy(30,1); cout << "Disciplina:";
	for (x=0; x<this->enderecoDisciplinas->vCodigos.size(); x++)
	{
			gotoxy(30,x+1); cout << this->enderecoDisciplinas->vNomes[x];
	}
	
	gotoxy(50,1); cout << "Notas:";
	for (x=0; x<this->enderecoNotas->vCodigosN.size(); x++)
	{
			gotoxy(50,x+1); cout << this->enderecoNotas->vNota[x];
	}
	
	gotoxy(80,1); cout << "Situacao:";
	for (x=0; x<this->enderecoNotas->vCodigoN.size(); x++)
	{
			gotoxy(80,x+1); cout << this->enderecoNotas->vNota[x];		
	}
	
	for(linha=linini; linha<=linfim; linha++)
	{
		gotoxy(colini, linha); cout<< char(186);
		gotoxy(colfim, linha); cout<< char(186);
	}
	
	gotoxy(colini, linini); cout<< char(201);
	gotoxy(colini, linfim); cout<< char(200);
	gotoxy(colfim, linini); cout<< char(187);
	gotoxy(colfim, linfim); cout<< char(188);
	

	getch();
}

void Funcoes::centralizar(string mensagem, int linha)
{
	int coluna;
	limparArea(2,linha,79,linha);
	coluna = (80-mensagem.size())/2;
	gotoxy(coluna,linha); cout<<mensagem;
}

string Funcoes::perguntar(string pergunta, int linha)
{
	string resposta;
	centralizar(pergunta,linha);
	resposta=getche();
	resposta=toupper(resposta[0]);
	return resposta;
}




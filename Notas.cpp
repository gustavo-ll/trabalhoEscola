Notas::Notas()
{
	ifstream arqNotas;
	arqNotas.open("Notas.txt");
	
	while (arqNotas.eof() == false)
	{
		getline(arqNotas, codigoN      , '#');
		getline(arqNotas, disciplinas  , '#');
		getline(arqNotas, alunos       , '#');
		getline(arqNotas, nota           );
		
		if (codigoN == "")
		{
			break;
		}
		else
		{
			vCodigosN.push_back(codigoN);
			vDisciplinas.push_back(disciplinas);
			vAlunos.push_back(alunos);
			vNota.push_back(nota);
		}
	}
	
	arqNotas.close();
}


string Notas::obterNotas(string cod)
{
	string nomeNotas;
	
	codigoN = cod;
	
	if (procurarCodigo()==true)
	{
		nomeNotas = nota;
	}
	else
	{
		nomeNotas = "Nao encontrada";
	}
	
	return nomeNotas;
}

void Notas::executarCRUD()
{
	string op;
	while(true)
	{
		clrscr();
		textcolor(YELLOW);
		gotoxy(20,1); cout << "Escola Manseira";
		textcolor(WHITE);
		gotoxy(20,4); cout << "1 - Cadastro";
		gotoxy(20,5); cout << "2 - Consulta";
		gotoxy(20,6); cout << "3 - Alteracao";
		gotoxy(20,7); cout << "4 - Exclusao";
		gotoxy(20,8); cout << "0 - Sair";
		gotoxy(20,9); cout << "Opcao : ";
		textcolor(LIGHTCYAN);
		op = getche();
		textcolor(WHITE);
		
		if (op=="0") break;
		if (op=="1") this->cadastrar();
		if (op=="2") this->consultar();
		if (op=="3") this->alterar();
		if (op=="4") this->excluir();
		
	}
}

void Notas::montarTela(string titulo, int linha) 
{
	textcolor(YELLOW);
	gotoxy(20,linha); cout << titulo;
	textcolor(WHITE);
	gotoxy(20,linha+1); cout << "Codigo Nota  :";
	gotoxy(20,linha+2); cout << "Codigo Disci :";
	gotoxy(20,linha+3); cout << "Codigo Auno  :";
	gotoxy(20,linha+4); cout << "Nota     :";
	
}

void Notas::cadastrar()
{
	string resp;
	
	
	
	montarTela("Cadastro de Pedidos");
	entrarDados(11);
	
	if (vAlunos.size()>2 || vDisciplinas.size()>2)
	{
		cout << "Ja possui 3 notas cadastradas";
		getch();
		clrscr();
		this->executarCRUD();
	}
	
		resp = perguntar("Confirma cadastro (S/N): ",20,16);
		if (resp == "S")
		{
		vCodigosN.push_back(codigoN);
		vDisciplinas.push_back(disciplinas);
		vAlunos.push_back(alunos);
		vNota.push_back(nota);
		
		gravarArquivo();
		}

	
	
	
}

string Notas::perguntar(string perg, int col, int lin)
{
	string resposta;
	
	gotoxy(col, lin);
	cout << perg;
	resposta = getche();
	resposta = toupper(resposta[0]);
	
	return resposta;
}

/*
char Notas::perguntar(string perg, int col, int lin)
{
	char resposta;
	
	gotoxy(col, lin);
	cout << perg;
	resposta = getche();
	resposta = toupper(resposta);
	
	return resposta;
}
*/

void Notas::entrarDados(int linha)
{
	textcolor(LIGHTCYAN);
	gotoxy(36,linha)  ; getline(cin, codigoN);
	gotoxy(36,linha+1); getline(cin, disciplinas);
	gotoxy(36,linha+2); getline(cin, alunos);
	gotoxy(36,linha+3); getline(cin, nota);
	textcolor(WHITE);
}

void Notas::consultar()
{
	bool achou;
			
	this->montarTela("Consulta de Notas");
	gotoxy(36,11); getline(cin, codigoN);

	if (procurarCodigo())
	{
		mostrarDados();
	}
	else
	{
		gotoxy(36,12); cout << "Nao encontrada";
	}		
	getch();
}

void Notas::mostrarDados()
{
	gotoxy(36,11); cout << codigoN;
	gotoxy(36,12); cout << disciplinas;
	gotoxy(36,13); cout << alunos;
	gotoxy(36,14); cout << nota;
}

void Notas::alterar()
{
	string resp;
	
	montarTela("Alteracao de Notas");
	gotoxy(36,11); getline(cin, codigoN);
	
	if (procurarCodigo()==true)
	{
		mostrarDados();
		
		montarTela("Novos dados",17);
		entrarDados(18);
		
		resp = perguntar("Confirma alteracao (S/N): ",20,16);
		if (resp == "S")
		{
			vCodigosN[indice] = codigoN;
			vDisciplinas[indice]   = disciplinas;
			vAlunos[indice]  = alunos;
			vNota[indice]  = nota;
			gravarArquivo();
		}
	}
	else
	{
		gotoxy(36,12); cout << "Nao encontrada";
	}		
	getch();
}

bool Notas::procurarCodigo()
{
	bool achou;

	achou = false;
	for (indice=0; indice<vCodigosN.size(); indice++)
	{
		if (vCodigosN[indice] == codigoN)
		{
			achou = true;
			
			vDisciplinas[indice]   = disciplinas;
			vAlunos[indice]  = alunos;
			vNota[indice]  = nota;
			
			break;
		}
	}
	return achou;
}

void Notas::excluir()
{
	string resp;
	
	montarTela("Exclusao de Notas");
	gotoxy(36,11); getline(cin, codigoN);
	
	
	if (procurarCodigo())
	{
		mostrarDados();
		resp = perguntar("Confirma exclusao (S/N): ",20,16);
		if (resp == "S")
		{
			vCodigosN.erase( vCodigosN.begin()+indice );
			vDisciplinas.erase( vDisciplinas.begin()+indice );
			vAlunos.erase( vAlunos.begin()+indice );
			vNota.erase( vNota.begin()+indice );
			gravarArquivo();
		}
	}
	else
	{
		gotoxy(36,12); cout << "Nao encontrada";
	}		
	getch();
}

void Notas::gravarArquivo()
{
	ofstream arqNotas;
	arqNotas.open("Notas.txt");
	
	for (indice=0; indice<vCodigosN.size(); indice++)
	{
		arqNotas << vCodigosN[indice]    << "#";
		arqNotas << vDisciplinas[indice] << "#";
		arqNotas << vAlunos[indice]      << "#";
		arqNotas << vNota[indice]     << endl;
	}
	arqNotas.close();
}

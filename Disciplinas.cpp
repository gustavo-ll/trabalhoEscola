Disciplinas::Disciplinas(Notas *enderecoNotas)
    {
    	ifstream arqDisciplinas;
    	arqDisciplinas.open("Disciplinas.txt");
    	this->endereco=enderecoNotas;
    	
    	while (arqDisciplinas.eof() == false)
    	{
    		getline(arqDisciplinas, codigo       , '#');
    		getline(arqDisciplinas, nome         );
    	
    		
    		if (codigo == "")
    		{
    			break;
    		}
    		else
    		{
    			vCodigos.push_back(codigo);
				vNomes.push_back(nome);
    		}
    	}
    	
    	arqDisciplinas.close();
    }

string Disciplinas::obterNome(string cod)
	{
		string nomeDisciplinas;
		
		codigo = cod;
		if (procurarCodigo()==true)
		{
			nomeDisciplinas = nome;
		}
		else
		{
			nomeDisciplinas = "Nao encontrada";
		}
		return nomeDisciplinas;
	}

void Disciplinas::executarCRUD()
	{
		string op;
		while(true)
		{
			clrscr();
			textcolor(YELLOW);
			gotoxy(20,1); cout << "Escola Manseira";
			textcolor(WHITE);
			gotoxy(20,2); cout << "1 - Cadastro";
			gotoxy(20,3); cout << "2 - Consulta";
			gotoxy(20,4); cout << "3 - Alteracao";
			gotoxy(20,5); cout << "4 - Exclusao";
			gotoxy(20,6); cout << "0 - Sair";
			gotoxy(20,7); cout << "Opcao : ";
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

void Disciplinas::montarTela(string titulo, int linha)
	{
		textcolor(YELLOW);
		gotoxy(20,linha); cout << titulo;
		textcolor(WHITE);
		gotoxy(20,linha+1); cout << "Codigo      :";
		gotoxy(20,linha+2); cout << "Nome        :";
	}
	
void Disciplinas::cadastrar()
	{
		string resp;
		
		montarTela("Cadastro de Disciplinas");
		entrarDados(11);
		
		resp = perguntar("Confirma cadastro (S/N): ",20,16);
		if (resp == "S")
		{
			vCodigos.push_back(codigo);
			vNomes.push_back(nome);
			gravarArquivo();
		}
	}

string Disciplinas::perguntar(string perg, int col, int lin)
	{
		string resposta;
		
		gotoxy(col, lin);
		cout << perg;
		resposta = getche();
		resposta = toupper(resposta[0]);
		
		return resposta;
    }
	
void Disciplinas::entrarDados(int linha)
	{
		textcolor(LIGHTCYAN);
		gotoxy(36,linha);   getline(cin, codigo);
		gotoxy(36,linha+1); getline(cin, nome);
		textcolor(WHITE);
	}

void Disciplinas::consultar()
	{
		bool achou;
				
		this->montarTela("Consulta de disciplinas");
		gotoxy(36,11); getline(cin, codigo);
			
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
	
void Disciplinas::mostrarDados()
	{
		gotoxy(36,11); cout << codigo;
		gotoxy(36,12); cout << nome;
	}
	
void Disciplinas::alterar()
	{
		string resp;
		
		montarTela("Alteracao de disciplina");
		gotoxy(36,11); getline(cin, codigo);
		
		if (procurarCodigo()==true)
		{
			mostrarDados();
			
			montarTela("Novos dados",17);
			entrarDados(18);
			
			resp = perguntar("Confirma alteracao (S/N): ",20,16);
			if (resp == "S")
			{
				vCodigos[indice]  = codigo;
				vNomes[indice]     = nome;
				gravarArquivo();
			}
		}
		else
		{
			gotoxy(36,12); cout << "Nao encontrada";
		}		
		getch();
	}
	
bool Disciplinas::procurarCodigo()
	{
		bool achou;

		achou = false;
		for (indice=0; indice<vCodigos.size(); indice++)
		{
			if (vCodigos[indice] == codigo)
			{
				achou = true;
				
				nome          = vNomes[indice];
				break;
			}
		}
		return achou;
	}

	
void Disciplinas::excluir()
	{
		string resp;
		bool achou;
		int x;
		
		achou==false;
		
		montarTela("Exclusao de disciplinas");
		gotoxy(36,11); getline(cin, codigo);
		
		for (x=0; x<this->endereco->vDisciplinas.size(); x++)
		{
			if (this->endereco->vDisciplinas[x] == codigo)
			{
				achou = true;
				gotoxy(36,12); cout << "Existem notas cadastradas nessa disciplina";
				getch();
				clrscr();
				break;
				executarCRUD();
			} 
			break;
		}
		
		if (procurarCodigo() && achou==false)
		{
			mostrarDados();
			resp = perguntar("Confirma exclusao (S/N): ",20,16);
			if (resp == "S")
			{
				excluiu==true;
				vCodigos.erase(vCodigos.begin()+indice);
				vNomes.erase(vNomes.begin()+indice);
				
				gravarArquivo();
				
			}
			else
			{
				gotoxy(36,12); cout << "Nao encontrada";
			}		
			getch();
		}
    }

void Disciplinas::gravarArquivo()
	{
		ofstream arqDisciplinas;
		arqDisciplinas.open("Disciplinas.txt");
		
		for (indice=0; indice<vCodigos.size(); indice++)
		{
			
			arqDisciplinas << vCodigos[indice] <<"#";
			arqDisciplinas << vNomes[indice]      ;
			
		}
		arqDisciplinas.close();
	}	

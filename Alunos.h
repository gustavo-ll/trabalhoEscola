class Alunos
{
	public:
	
    Alunos(Notas *enderecoNotas);
	void executarCRUD();
	
	
	private:
	
	string codigo, nome;
	vector<string> vCodigos, vNomes;
	int indice;
	Notas *endereco;		
	
	string obterNome(string cod);
	void montarTela(string titulo, int linha=10);
	void cadastrar();
	string perguntar(string perg, int col, int lin);
	void entrarDados(int linha);
	void consultar();
	void mostrarDados();
	void alterar();
	bool procurarCodigo();
	void excluir();
	void gravarArquivo();
};

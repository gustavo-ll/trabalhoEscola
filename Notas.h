class Notas
{
	public:
		
    Notas();
    void executarCRUD();
    void gravarArquivo();
	
	
	vector<string> vAlunos, vDisciplinas;
	string nota, codigoN, alunos, disciplinas;
	vector<string> vNota, vCodigosN;
	int indice;	

	private:
		
	
	
	void montarTela(string titulo, int linha=10);
	void cadastrar();
	string perguntar(string perg, int col, int lin);
	void entrarDados(int linha);
	void consultar();
	void mostrarDados();
	void alterar();
	bool procurarCodigo();
	void excluir();
	
	void excluirDisciplinas();
	string obterNotas(string codN);	

};

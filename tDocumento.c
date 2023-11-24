#include "tDocumento.h"

struct tDocumento
{
    void* dado;
    func_ptr_imprimeEmArquivo imprimeArquivo;
    func_ptr_imprimeNaTela imprimeTela;
    func_ptr_desaloca desalocaDoc;
};


/**
 * Função que recebe um dado genérico (representando um tipo de documento) e suas funções de callback.
 * A função cria um Documento e retorna um ponteiro para ele.
 */
tDocumento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela,
func_ptr_imprimeEmArquivo imprimeEmArquivo, func_ptr_desaloca desaloca){
    
    tDocumento *doc = (tDocumento *) calloc(1,sizeof(tDocumento));
    if (doc == NULL) {
        perror("Erro ao alocar memória para o documento");
        exit(EXIT_FAILURE);
    }

    doc->dado = dado;
    doc->imprimeTela = imprimeNaTela;
    doc->imprimeArquivo = imprimeEmArquivo;
    doc->desalocaDoc = desaloca;

    return doc;

}

/**
 * Função que recebe um Documento e o desaloca. O dado genérico também deve ser desalocado
 * dentro dessa função.
 */
void desalocaDocumento(tDocumento *doc){
    if(doc){
        doc->desalocaDoc(doc->dado);
        free(doc);
    }
}

/**
 * Função que recebe um Documento genérico e o imprime na tela.
 */
void imprimeNaTelaDocumento(tDocumento *doc){
    doc->imprimeTela(doc->dado);
}

/**
 * Função que recebe um Documento genérico e o imprime em um arquivo.
 * O path representa o caminho até o diretório onde o arquivo será criado ou editado.
 */
void imprimeEmArquivoDocumento(tDocumento *doc, char *path){
    doc->imprimeArquivo(doc->dado, path);
}
using UnityEngine;
using TMPro;

public class ColetaItem : MonoBehaviour
{
    public TMP_Text pontuacaoText; // Referência para o texto na UI
    private int pontuacao = 0;     // Valor inicial da pontuação

    void Start()
    {
        AtualizarTextoPontuacao(); // Atualiza o texto ao iniciar
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("ItemColetavel"))
        {
            Destroy(other.gameObject); // Remove o item do cenário
            pontuacao += 10;           // Incrementa a pontuação
            AtualizarTextoPontuacao(); // Atualiza o texto
        }
    }

    void AtualizarTextoPontuacao()
    {
        pontuacaoText.text = "Pontuação: " + pontuacao; // Formata o texto com o valor atual
    }
}

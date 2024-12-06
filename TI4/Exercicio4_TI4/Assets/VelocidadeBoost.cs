using System.Collections;
using UnityEngine;

public class VelocidadeBoost : MonoBehaviour
{
    private PersonagemMovimento personagemMovimento;
    private float boostDuration = 4f;

    void Start()
    {
        personagemMovimento = GetComponent<PersonagemMovimento>();
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("ItemVelocidade"))
        {
            Destroy(other.gameObject);
            StartCoroutine(AumentarVelocidade());
        }
    }

    private IEnumerator AumentarVelocidade()
    {
        float velocidadeOriginal = personagemMovimento.velocidade;
        personagemMovimento.velocidade *= 2;
        yield return new WaitForSeconds(boostDuration);
        personagemMovimento.velocidade = velocidadeOriginal;
    }
}
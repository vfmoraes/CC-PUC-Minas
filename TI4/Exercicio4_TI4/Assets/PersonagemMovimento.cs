using UnityEngine;

public class PersonagemMovimento : MonoBehaviour
{
    public float velocidade = 5f;

    void Update()
    {
        float horizontal = Input.GetAxis("Horizontal");
        float vertical = Input.GetAxis("Vertical");

        Vector3 movimento = new Vector3(horizontal, 0, vertical);
        transform.Translate(movimento * velocidade * Time.deltaTime);
    }
}

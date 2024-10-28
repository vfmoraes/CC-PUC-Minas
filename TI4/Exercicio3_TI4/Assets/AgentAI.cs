using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class AgentAI : MonoBehaviour
{
    public List<Transform> waypoint;

    NavMeshAgent navMeshAgent;

    public int currentWayPointIndex = 0;


    // Start is called before the first frame update
    void Start()
    {
        navMeshAgent = GetComponent<NavMeshAgent>();
    }

    // Update is called once per frame
    void Update()
    {
        Walking();
    }

    void Walking(){
    

        if(waypoint.Count == 0){
            return;
        }

        float distanceToWayPoint = Vector3.Distance(waypoint[currentWayPointIndex].position, transform.position);

        if(distanceToWayPoint <= 2){
            currentWayPointIndex = (currentWayPointIndex + 1) % waypoint.Count;
        }

        navMeshAgent.SetDestination(waypoint[currentWayPointIndex].position);
    }
}

bool Graph::ifPathExists(string vertex1, string vertex2)
{
    vertex* s;
    for(int i=0; i<(int)vertices.size(); i++)
    {
        if(vertices[i].name == vertex1)
        {
            s = &vertices[i];
        }
    }
    
    s-> visited = true;
    queue<vertex*> q;
    q.push(s);
    vertex* n;
    while(!q.empty())
    {
        
        n = q.front();
        q.pop();
        for(int i=0; i<(int)n->adj.size(); i++)
        {
            if(n->adj[i].v->name == vertex2)
            {
                cout<<"True"<<endl;
                return 1;
            }
            
            if(n->adj[i].v->visited==false)
            {
                n->adj[i].v->visited = true;
                q.push(n->adj[i].v);
            }
        }
    }
    return 0;
}
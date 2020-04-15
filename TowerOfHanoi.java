import java.util.*;
class Tower
{
    String name;
    Stack<Integer> disc;
    Tower(String name)
    {
        this.name = name;
        disc = new Stack<Integer>();
    }
    public void push(int d)
    {
        if(disc.size() > 0 && d>disc.peek())
        throw new RuntimeException("Not allowed to put bigger disc on smaller one");
        disc.push(d); 
    }
    public int peek()
    {
        if(disc.size()==0)
        throw new RuntimeException("disc "+name+" is Empty");
        return disc.peek();
    }
    public int pop()
    {
        if(disc.size()==0)
        throw new RuntimeException("disc "+name+" is Empty");
        return disc.pop();
    }
    public int size()
    {
        return disc.size();
    }
    public String toString()
    {
        return "Tower " + name + " " + disc;
    }
}
class TowerOfHanoi
{
    public static void solve(Tower from , Tower helper , Tower to, int n)
    {
        if(n==0)
        return;
        solve(from , to , helper,n-1);
        move(from , to);
        solve(helper, from , to , n-1);
    }
    public static void move(Tower from , Tower to)
    {
        if(from.size() == 0)
        {
            throw new RuntimeException("disc "+from.name+" is Empty");
        }
        System.out.println("moving " + from.peek() + " from "+from.name+" to "+to.name);
        to.push(from.pop());
    }
    public static void main(String args[])
    {
        Tower a = new Tower("a");
        Tower b = new Tower("b");
        Tower c = new Tower("c");
        a.push(4);
        a.push(3);
        a.push(2);
        a.push(1);
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        solve(a,b,c,4);
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }
}




# threads in java 
->a thread of execution in a program is like(virtual CPU)
The JVM allows an application to have multiple threads running concurrently
* each thread can execute parts of you code in parallel with main thread 
* each thread has priority
* threads with higher priority are executed 1st and lower priority

** The JVM continues to execute threads until either of the 
1. The exit method of class Runtime has been called
2. All user threads have died


** when JVM starts it searches for the "main" which is the starting point of thread **

Daemon thread is a low priority thread which runs behind the main thread 




# program

public class Main{
       public static void main(String[] args){
              
       }
}


# MULTITHREADING IN JAVA




->multiple task (executing task simultaneously)
->main code->(thread1,thread2,thread3.....threadn)
[graphic]   [responding to key strokes]   [grammer check]
                        |
                 word proccessor
                         |
                       CPU

multitasking->through multiple programs in a resource system            multi-threading->through same processor and same programs

**threads in java**
note:at one time one thread is executed

multithreading is mostly used in multitasking
->independent to each other
->does not block the user 
->save time
->other thread does not affected while in exception 


java threads states are:
->new = instance of thread class new state
->runnable = state where the thread is not selected 
->running =selected state
->non-runnable(block state due to sleep )=>specifies sleep time- **lock**/dead
->terminated




runnable state    <------
 *yeild()*  |              | 
            |              | *notify()/notifyAll() when sleep time is up resume()*
       running ------->non-runnable state *waiting()/sleeping()/blocking*

# 2 ways to create a thread in java
extending thread class
implementing runnable class

# starting a thread

start() method is used to create a thread 


# threads Synchronization

> Threads share the same memory space , they can share the same memory space resource (objects)
> however , there are critical situations where it is desirable that only one thread at a time has access to shared resource.

example. booking of seat in theatre:



*****Java Synchronized Method***** *to avoid Race condition*


If you declare any method as synchronized, it is known as synchronized method. 
[access-modifier] synchronized return_type name(param){}

Synchronized method is used to lock an object for any shared resource.

**using Object as lock**
we can use any object as lock but not any primitive types such as int,float,etc..

the lock can be used to execute a block of code for only a single thread at a time 

>>>>Without using Lock
if we specify [Thread.sleep(1000)] in try block then next Thread will execute in the meantime // which will develop confusion and termination of program happens 
*in case of non-static method*
synchronized(this){
       //codes to be executed by a class / JOB codes
}
>>the above one is same as the synchronized method

*in case of static method*
synchronized([classname].class){
       //codes to be executes/ runnable codes
}

When a thread invokes a synchronized method, it automatically acquires the lock for that object and releases it when the thread completes its task.
>>>>>>
# Rules for synchronization
1. A thread must acquire the object lock associated with a shared resource before it can enter the shared resource.
2. the runtime system ensures that no other thread can enter a shared resource if another thread already holds the object associated with it.
3. if a thread cannot immediatley acquire the  object lock , it is blocked i.e it must wait for the lock to become available.
4. when a thread exits a shared resouce ,the runtime system ensures that the object lock is also relinquished, if another thread is waiting for this object lock, it can try acquire the lock in order to gain access to shared resource.
5. it should made clear to not to make any assumptions of the output pattern of multiple thread .

# static Synchronized methods
1. a thread acquiring the lock of a class to execute a static synchronized methos has no effect on any thread acquiring the lock on any object of the class to execute a synchronized instance methods
2. in other words , synchronized of static methods in a class is independent from the synchronized of instance methods of an objects of the class
3. a subclass decides whether the new defintion of an inherited synchronized mehod will remain synchronized in the subclass.


# Race condition
it occurs when two or more threads simultaneouly update the same value(stackTopIndex) and, as a consequence , leave the valuein an undefined or inconsistent state.


# volatile Keywork




# Schedules this thread to begin execution. The thread will executeindependently of the current thread. 
# A thread can be started at most once. In particular, a thread can notbe restarted after it has terminated.
# Throws:IllegalThreadStateException - if the thread was already started**

# ThreadsPriority 


> Get and Set methods in Threads priority 
> integerPrioirty()
> setPriority(int newPriority) => throws IllegalArgumentException if we try to give Priority above 10 or less than 1


1. getting and setting name of the Threads
2. Thread Priorities 

3. The methods to prevent Thread execution
> yield()
> join()
> sleep()

4. Synchronization

5. Inter thread Communication
6. DeadLock
7. Deamon Threads
8. multithreadings enhancement


# String handling in java
> strings are immutable in java
> declaring strings can be found in two ways
+ by using string literal
+ by using new reference to the string constructor

Strings MEthods in java
1. indexOf()
2. stringanme.length
3. stringname.concat(string-content) //but the content will not change in the contacted strings stringname and string-content
4. boolean equals(object otherobject)//compares to objects
5. lastIndexOf(String s)
6. equalsIgnoreCase(string anotherString)
7. compareTo(string another) // itn out=s1.compareTo(s2) out=0 or out>0 or out<0 
8. stringname.substring(starts,end-1)//index value are taken
9. compareToIgnoreCase()
10. toLowerCase()
11. toUpperCase()
12. String trim()
13. String replace ()


String s1="hi";
String s2="hi";
s1.equals(s2)=>gives true because of content in the s1 and s2
> cuz they are different reference to each other
s1==s2 // gives false because they are comparing the reference of s1 and s2

String s1=new String("hi");
String s2=new String("hi");
s1.equals(s2);
gives false because they are refereing to different objects
but



# COLLECTION INTERFACE
1. List 
2. Set
3. Queue

ArrayList<> are ordered List (we can access each element by using index value)
>>>arraylist.add(element) will add element to the arraylist

>>>arraylist.addAll(arraylist1) will add the arraylist1 to the arraylist 

>>arraylist.get(indexvalue) will give the element at the index value

>>arraylist.set(indexvalue,Element) will replace the element at the specified index value  *Modifiying*

**Predicate in Java**

example :
"Student names whose starts with letter "a" at the starts comes out is a predicate"
arraylist.remove(indexvalue) //will remove the value at the specified index value

arraylist.removeIf(new Predicate<String>){
       @Override
       public boolean test(String s){
              return s.startsWith("C");
       }
}

# Iterator

> in  java.util.Iterator
methods
  >Iterator<E> name=collection.iterator();
  >name.next() // go move to next element in the collection (current element in the collection)
  >name.hasNext() // commonly used in while loop 
> name.remove()
>name.forEachRemaining()
# Map





# Regular Expression in java (Impoe)

>
java.util.regex package
The Matcher and Pattern classes provide the facility of Java regular expression. The java.util.regex package provides following classes and interfaces for regular expressions.

MatchResult interface
Matcher class
Pattern class
PatternSyntaxException class








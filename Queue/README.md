# Queue.h

This is a queue library implementation on arduino
    
## Documentation

Queue : 

    ```
    .push(value) - insert value at the end 
    .pop() - removes the first element
    .front() - access the first element
    .back() - access the last element
    .empty() - checks whether the queue is empty
    .full() - checks whether the queue is full
    .size() - return the number of elements
    .clear() - removes all elements in the queue
    ```
    
## Examples
Here are some example for the Queue libary :

  ```
    Queue<int> queue(5); // Make a Queue with max 5 int
    
    queue.push(5); // Inserting 5 into the first queue
    queue.push(10); // Inserting 10 into the second queue
    queue.push(15);
    queue.push(20);
    queue.push(25);
    
    if (!queue.empty()) 
    {
        Serial.println("count : ");
        Serial.println(queue.size()); // the size of the queue (5)

        Serial.println("full : ");
        Serial.println(queue.full()); // check if the queue full (1 = true)

        Serial.println("queue front : ");
        Serial.println(queue.front()); // print the first value print 5

        Serial.println("queue back : ");
        Serial.println(queue.back()); // print the last value print 25

        Serial.println("queue pop value : ");
        Serial.println(queue.pop()); // print and remove the first value from the queue (5)

        Serial.println("clearing queue ");
        Serial.println(queue.clear()); // clear the queue
    }
  ```


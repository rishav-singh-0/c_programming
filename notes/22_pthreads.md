# Pthread

- A thread is a single sequence stream within a process. Because threads have
  some of the properties of processes, they are sometimes called lightweight
  processes.
- All threads share data segment. Global and static variables are stored in
  data segment. Therefore, they are shared by all threads. So, accessing a
  global variable in a thread is generally a bad idea. What if thread 2 has
  priority over thread 1 and thread 1 needs to change the variable. In
  practice, if it is required to access global variable by multiple threads,
  then they should be accessed using a mutex.

## Functions

### pthread_create
Used to create a new thread

``` c
int pthread_create(pthread_t * thread, 
                   const pthread_attr_t * attr, 
                   void * (*start_routine)(void *), 
                   void *arg);
```

Parameters:
- thread: pointer to an unsigned integer value that returns the thread id of
  the thread created.
- attr: pointer to a structure that is used to define thread attributes like
  detached state, scheduling policy, stack address, etc. Set to NULL for
  default thread attributes.
- start_routine: pointer to a subroutine that is executed by the thread. The
  return type and parameter type of the subroutine must be of type void *. The
  function has a single attribute but if multiple values need to be passed to
  the function, a struct must be used.
- arg: pointer to void that contains the arguments to the function defined in
  the earlier argument

### pthread_exit
Used to terminate a thread

``` c
void pthread_exit(void *retval);
```

Parameters:
This method accepts a mandatory parameter retval which is the pointer to an
integer that stores the return status of the thread terminated. The scope of
this variable must be global so that any thread waiting to join this thread may
read the return status.

### pthread_join
Used to wait for the termination of a thread.

``` c
int pthread_join(pthread_t th, 
                 void **thread_return);
```

Parameter: 
This method accepts following parameters:
- th: thread id of the thread for which the current thread wait
- thread_return: pointer to the location where the exit status of the thread
  mentioned in th is stored.

### pthread_self
Used to get the thread id of the current thread.

``` c
pthread_t pthread_self(void);
```


### pthread_equal
Compares whether two threads are the same or not. If the two threads are equal,
the function returns a non-zero value otherwise zero.

``` c
int pthread_equal(pthread_t t1, 
                  pthread_t t2);
```

Parameters:
This method accepts following parameters:
- t1: the thread id of the first thread
- t2: the thread id of the second thread

### pthread_cancel
Used to send a cancellation request to a thread

``` c
int pthread_cancel(pthread_t thread);
```

Parameter: 
This method accepts a mandatory parameter thread which is the thread id of the
thread to which cancel request is sent.

### pthread_detach
Used to detach a thread. A detached thread does not require a thread to join on
terminating. The resources of the thread are automatically released after
terminating if the thread is detached.

``` c
int pthread_detach(pthread_t thread);
```

Parameter:
This method accepts a mandatory parameter thread which is the thread id of the
thread that must be detached.

### pthread_tryjoin_np
The `pthread_tryjoin_np()` function performs a nonblocking join with the thread
thread, returning the exit status of the thread in *retval.  If thread has not
yet terminated, then instead of blocking, as is done by `pthread_join()`, the
call returns an error.

``` c
#define _GNU_SOURCE     // before pthread include

int pthread_tryjoin_np(pthread_t thread, void **retval);
```

### pthread_cleanup_pop
### shmget

## Semaphores

### sem_init

``` c
int sem_init(sem_t *sem, int pshared, unsigned int value)
```
Initialize semaphore object SEM to VALUE. If PSHARED then share it with other processes.

### sem_wait

``` c
int sem_wait(sem_t *sem)
```
Checks if `sem` is equal to `0` then wait for it to become non-zero
If `sem > 0` then decrement sem ie. `sem--` and execute the block of code.

### sem_post

``` c
int sem_post(sem_t *sem)
```
Increment `sem` by `1` ie. `sem++` and execute the block of code.

## Diffrence between Binary Semaphores and Mutex

Locking and unlocking mutex in diffrent threads will have undefined behaviour
which should always be avoided. So semaphores should be used in this case.

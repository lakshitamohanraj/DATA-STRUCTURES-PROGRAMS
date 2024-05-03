# Data models
 Underlying structure of a databases
 conceptual

 data+relationship +semantics+Constraints
 design the databse at physical level logical level and in


 # categorise of data models

__realtional models__

 #every t-(collection of tables , tables represent both data and relationship=> relationship among the tables  , multiple columns with the unique names)

`tables=relation ==> record based models /fixed -format of the records of several types/`
# each record contains fields and attributes
most widely used data model-realtional model


___entity-relationhip model__-( 
    *E-R DATA* models or er model
   - collection of basic objects called entites and its
   - relationship.
   - an entity is a real world thing or object
   - distinguishable from other objects
    - widely used in database design.
    - 
     )
**object -based model** 
- oop language -c+ java c# etc
- nested for object oriented data models
- object based model=E-R MODEL + OO FEATURES(data encapsulation , inheritance and adsatrction ect)
- *object -relational data model= object based model + relation model*

# semistrcuted data models( mainly on transfering of data)
- specification of datas
- individual data items of same type may have different sets of attributes;
- contrast to previous models
- language this support this model is XML
example for XML

<note>
  <from> neso academy</from>
  <to>all subjects</to>
  <subjects>thank you</subject>
  <body>thank you for subscribing neso academy </body>
 </note>



==============================
__E-R MODEL DIAGRAMS AND ITS TERMINOLOGIES__

*entity*
- a thing in the real world an independent exitsneces
- act like a object like car , physical existences 
(or like a conceptual existences like course , degree)

**composite attribute**  - which can be divied into its subsets (name ,2st name , middle name etc)
**simple attribute**- which have only one value / connot be divied further 
example weight 

- **single values attribute** - only one value for particular entity (age ,date of birth)
- **multivalued attributes**- has more than one value(degree, language known)

**deriverd attributes**-which derived from stored attributes 
age-> data_of_bath

**stored attribute**- which have a stored value in it , age

**entity type**- a collection of entities of same attribute
**entity set** - a set of records from entity set

__key attribute__
- that attribute that is capable of identifying each attribute uniquely 
roll no ,id etc


__value set of attributes__ - the set of attribute can be assigned to an attribute

### RELATIONSHIPS CONCEPTS IN ER DIAGRAMS

- relationship-> associates among 2 or more entites 
ex. techer *teches* students

*degree of relationship set*
- denotes the number of entity types that participates in the relationship
  ex. unary relationship   diagram 
- binary relationship
         publisher--  *publishes* -- book
 -ternary relationship  

relationship constraints 
- maxium number of relationship instances that an entity can participate in
- possible cardinality ratios for binary relationship -> 1:1 ,1:N, n:1, m:n

**2 participation constrainst**- specfies whether the existence of an entity depends on its negin related to another entity
- # total participation and partial participation
- total participation is represented by doubly line b/w relation ad entity
- partial particpation by single lined b./w the same


>>>>>Attributes of relationship types
@ in 1:1 relationship type the attributes are migrates either side of the entity
@ in n:1 or 1:n the attributes are migrated from n side of the entity
 @ in m:n type 

 role names 
 - __signifies the role__ that a participating entity plays in each relationship instances
 recrusive relationship 
 -          employee 
            /       \
   supervisor    supervisee
           "superviose" relation 


# ENCHANED ER MODELS EER MODELS
*generalization*(in general combining) - __bottom -up approach__ where  lower level entites are combined to form higher level entites.

*specilization* 
- __top down approach__ where it defines a set of sub entities from the parent / higher entity.



=======================================================





# ORGANIZARION OF RECORDS IN FILES
>heap file organization(heap files)
>sequential organization (sorted files)
>hashing file organisation

*heap file*  
>works with blocks
>NO sorting and ordering is required in this method
(if the a block is full automatically create a new block to insert the datas)
>datas are inserted at the end of the block
> if the database is huge -> deleting,updating,searching takes up a lot of time ==> traverse the data from the beginning of the file

*sequential filr organization* ->files are stored in the ordered and serial ways
two ways to implement the method
> Pile file method(ordered)
> sorted file method(unordered)
 => Pile file method
 1. the file contains many numbers of records simply placed in a sequencial order
 2. inserting the new record will be at the end of the file 
 3. now the inserted record will be the end of file
 
 => sorted file method
 1. storing of the records can be done either in the ascending order or descending order 
 2. the new record can inserted in between the file by following the order 
 
 *Hashing techique* (randomizing function)  yeilds the address of the disk block
  > primary file organization , which provides immediate fast access response
  >called as hash file
  > the datas are stored in the main memory block 
  H(k) = K mod M
  M- size of the block 
  H(k)= hash function
  K-search key value to serach 

# static hashing 
we cant able to change the address of the memory location 



> two types of static hashing 
> open hashing and closed hashing 

*opeartion in Static hashing*
> searching , updation deletion ,insertion etc.

OPEN HASHING 
> linear probing 
> search a place to be stored / free block so that the insertion is done efficiently 
> new record is inserted in the data buckets if the current bucket is full checks the next block if it is not full immediately the new record is inserted in the next block

CLOSE HASHING
> Overflow chaining 
> new record is inserted in the data buckets if the current bucket is overflow/full then this hashing will create a new block with same memory address and inserted the new record in it

## Dynamic hashing 

the memory is located address is automatically creates from the previous data buckets binary address difference of 2 bits

## RAID
**Redunancy array Independent Disk**
> RAID 0
> provides data stripping 


# RAID 0
>RAID level 0 provides data stripping, i.e., a data can place across multiple disks. It is based on stripping that means if one disk fails then all data in the array is lost.

>This level doesn't provide fault tolerance but increases the system performance

Pros of RAID 0:
1. In this level, throughput is increased because multiple data requests probably not on the same disk.
2. This level full utilizes the disk space and provides high performance.
3. It requires minimum 2 drives.
Cons of RAID 0:
1. It doesn't contain any error detection mechanism.
2. The RAID 0 is not a true RAID because it is not fault-tolerance.
3. In this level, failure of either disk results in complete data loss in respective array.


# RAID 1
> This level is called mirroring of data as it copies the data from drive 1 to drive 2. It provides 100% redundancy in case of a failure.

Pros of RAID 1:
1. The main advantage of RAID 1 is fault tolerance. In this level, if one disk fails, then the other automatically takes over.
2. In this level, the array will function even if any one of the drives fails.
Cons of RAID 1:
1. In this level, one extra drive is required per drive for mirroring, so the expense is higher



# RAID 2
> RAID 2 consists of bit-level striping using hamming code parity. In this level, each data bit in a word is recorded on a separate disk and ECC code of data words is stored on different set disks.
>Due to its high cost and complex structure, this level is not commercially used. This same performance can be achieved by RAID 3 at a lower cost.
*Pros of RAID 2:*
1. This level uses one designated drive to store parity.
2. It uses the hamming code for error detection.
*Cons of RAID 2:*
1. It requires an additional drive for error detection.


# RAID 3
>RAID 3 consists of byte-level striping with dedicated parity. In this level, the parity information is stored for each disk section and written to a dedicated parity drive.
1. In case of drive failure, the parity drive is accessed, and data is reconstructed from the remaining devices. Once the failed drive is replaced, the missing data can be restored on the new drive.
2. In this level, data can be transferred in bulk. Thus high-speed data transmission is possible.



> Pros of RAID 3:
1. In this level, data is regenerated using parity drive.
2. It contains high data transfer rates.
3. In this level, data is accessed in parallel.
> Cons of RAID 3:
1. It required an additional drive for parity.
2. It gives a slow performance for operating on small sized files.






# INDEXING TECHNIQUES
















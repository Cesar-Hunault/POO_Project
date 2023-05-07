# Software for managing a fictitious X-ray center

## Description
Implementation of a software that allows practitioners to efficiently manage patient files and assist in follow-up and diagnosis. The source code of the software is entirely implemented in C++. 

>Authors: César HUNAULT, Romain LEVERGEOIS </br>
>Last update: 27/11/2022</br>
>>Based on the course of Pr M.Oussalah 'Object-oriented programming for biologists'.

## Requested specifications

- The software must allow the connection of a user and its differentiation: practitioner or patient of the X-ray center.
- A practitioner must be able to manage all examinations easily. He must be able to:
  - Display X-rays:
    - that concern him,
    - by exam number,
    - by patient ID,
    - by date of completion.
  - Modify X-rays
  - Delete X-rays
  - Saving and loading data from files    
    
- A patient in the radiology center who logs into the software should be able to see his results when they are available, and the date of his future scheduled x-rays.    

- **Personal Choices:**
  - Add to radiologist profiles the ability to create a profile for a new practitioner.
  - Implement the software within a graphical interface allowing for better clarity and a more professional and accomplished result than an executable version in the terminal.
    
Two versions of the software were produced for this project. The first version is the prototype, it runs in the terminal and all the functionalities presented previously are available and functional. The second version runs in a graphical interface (also programmed in C++) using the library Gtkmm library, but is still incomplete.

## Software architecture 

![alt text](https://github.com/Cesar-Hunault/POO_Project/blob/master/UML_graph.svg?raw=true)


## Use (in a Linux shell)

To use the prototype version of the software, you must go to the src_sans_interface folder of the archive and execute the main file.

```
$ cd src_sans_interface/
$ ./main
```

To use the graphic version of the software, gtkmm must be installed on the machine. This can be done with the command: 
```
sudo apt install libgtkmm-3.0-dev.
```
then go to the src_avec_interface folder of the archive and run the
interface file.

```
$ cd src_avec_interface/
$ ./interface
```
## Connexion

We advise to use the login ***cesar*** and the password ***123*** in order to connect as a radiologist since it already contains some associated data, and the login ***4*** and the password ***111*** in order to connect as a patient to have the visualization of the patient result of the demonstration. The other existing identifiers and passwords are present in the database BD_login.txt.

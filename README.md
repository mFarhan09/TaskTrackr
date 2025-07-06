 Description
TaskTrackr is a desktop-based task management application built using C++ and Qt. It follows the Model-View-Programming (MVP) architecture and implements core Qt concepts such as dynamic dialogs, signal-slot communication, and modular component design.

This project is part of my learning journey in mastering real-world Qt development, with a focus on building robust and scalable desktop applications.

Features Implemented
Add tasks using a modal dialog form (AddTaskDialog)

Use of signals and slots to connect UI events with application logic

TaskModel (inherits QAbstractListModel) for managing a list of tasks

QListView used to display tasks

Real-time updates in the view when new tasks are added

Each task includes:

Title

Description

Deadline

Category

Priority

Status

Concepts Learned
Qt Model-View-Programming (MVP) structure

Creating and using custom dialog windows for form input

Designing UI using Qt Widgets and Layouts

Emitting and handling custom signals

Managing dynamic data using QAbstractListModel

 Upcoming Work
Implement task editing and deletion

Add filtering and sorting options

Save/load task data using JSON

Style tasks with a custom delegate (card layout)

Timer-based reminders and due-soon logic

Technologies Used
C++

Qt 6 Widgets

Signal & Slot Mechanism

Object-Oriented Programming.

# 📘 Facebook Clone - OOP Project in C++ 

## 🚀 Overview

This project is a simplified Facebook clone implemented in C++ using Object-Oriented Programming principles. It simulates core features of Facebook such as users, pages, posts, comments, likes, activities, and timelines.

## ✨ Features

- 👤 User management with friends list and liked pages
- 📄 Page creation and management
- 📝 Posting different types of posts including text and activities
- 💬 Commenting on posts
- 👍 Liking posts and pages
- 🕒 Timeline and page feed viewing
- 📅 Date handling for posts and activities

## 🏗️ Classes

- **User**: Represents a Facebook user with attributes like first name, last name, friends, liked pages, and timeline posts.
- **Page**: Represents a Facebook page with posts shared on its timeline.
- **Post**: Base class for posts, supporting text posts and activity posts.
- **Comment**: Represents comments on posts.
- **Activity**: Represents user activities such as feeling, thinking about, making, or celebrating something.
- **Date**: Handles date information for posts and activities.
- **Helper**: Contains utility functions for string manipulation and conversions.
- **Memory**: Derived from Post, represents shared posts (memories).

## 🛠️ Usage

- Compile the project using a C++ compiler supporting C++11 or later.
- Run the executable to interact with the Facebook clone simulation.
- Data can be loaded from files for users, pages, posts, and activities.
- The program supports adding friends, liking pages, posting content, commenting, and viewing timelines.

## 📦 Installation

1. Clone the repository:
2. Compile the source code:
3. Run the program:



## 🗂️ Project Structure

- `fb_clone.cpp` - Main source file containing all class definitions and program logic.
- Data files (if any) - Used to load initial data for users, pages, posts, etc.

## ⚠️ Limitations

- Maximum limits on friends, liked pages, posts, and comments are hardcoded (usually 10).
- Basic console-based interface without GUI.
- Memory management handled manually; ensure proper usage to avoid leaks.

## 👤 Author

- Abdullah Nadeem

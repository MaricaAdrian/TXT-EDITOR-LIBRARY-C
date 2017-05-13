% preamble

\documentclass{article}
%% \usepackage{times}
\usepackage{latexsym}
\usepackage{graphicx}
\usepackage{url}
\usepackage{hyperref}
\usepackage{listings}
\hypersetup{colorlinks=true}


\begin{document}

% top matter

\title{Text Editor Library, Spring 2017}
\author{Marica Adrian-Gabriel}
\date{\today}
\maketitle

\begin{tabbing}
\\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\
\end{tabbing}

\begin{tabbing}
\indent{Teachers:}  \=\ {Costin B\u{a}dic\u{a} and Alex Becheru} \\
\indent{Section:}   \=\  {Computers with teaching in Romanian Class} \\
\indent{Group:}      \>  C.R. 1.2.  \\
\indent{Year of study:} \=\ {I}

\end{tabbing}

\pagebreak
% sections
\section{Problem statement}
\ \ \ \  Text editor library. Write a library with functions that could be useful for a text editor. The library should at least contain the following functions:
\begin{itemize}
    \item determine if a word is present in a document.
    \item determine the number of occurrences for a word in a document. 
    \item replace all instances of a word in a document with another given word.
    \item replace speciﬁc instances of a word in a document with another given word, e.g. replace the 3rd appearance of a word with another given word. 
    \item create a sorted list of words by the number of occurrences in a document.

\end{itemize}

\section{Pseudocode}


\lstset{
  language=C,                % choose the language of the code
  numbers=left,                   % where to put the line-numbers
  stepnumber=1,                   % the step between two line-numbers.        
  numbersep=5pt,                  % how far the line-numbers are from the code
  backgroundcolor=\color{white},  % choose the background color. You must add \usepackage{color}
  showspaces=false,               % show spaces adding particular underscores
  showstringspaces=false,         % underline spaces within strings
  showtabs=false,                 % show tabs within strings adding particular underscores
  tabsize=4,                      % sets default tabsize to 2 spaces
  captionpos=b,                   % sets the caption-position to bottom
  breaklines=true,                % sets automatic line breaking
  breakatwhitespace=true,         % sets if automatic breaks should only happen at whitespace \lstinputlisting;
}

\begin{lstlisting}

void read_file (char file[G_MAX_WORD_LENGTH]) {

    unsigned int counter = 0;
    FILE *f = fopen(file, "r");

    if (f == NULL)
    {
        printf("\nError opening file!");
		return;
    }


    while (fscanf(f, " %255s", G_STRING[counter]) == 1 && counter != G_MAX_WORDS) {
        ++counter;
    }
	
    fclose(f);
	
	if(counter > 0){
		G_FILE_LOADED++;
		printf("\nFile read successfully.");
	} else {
		printf("\nNo words found in the file.");
	}
	
}


void print_file(){

	if(G_FILE_LOADED == 0){
		
		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;
		
	}

	unsigned int counter = 0;

	printf("\nYour file content is: ");

	while(G_STRING[counter][0] != '\0'){

	printf(" %s", G_STRING[counter]);
	++counter;

	}

}

void save_to_file(char file[G_MAX_WORD_LENGTH]){

	if(G_FILE_LOADED == 0){
		
		printf("\nNo file loaded. Read a file before trying to do operations.");
		return;
		
	}

    int counter = 0;

    FILE *f = fopen(file, "w+");

    if (f == NULL)
    {
        printf("\nError saving to file!");
        return;
    }

    while(G_STRING[counter][0] != '\0'){

        fprintf(f, "%s ", G_STRING[counter]);
        ++counter;

    }

    fclose(f);

    printf("\nYour content has been saved to file \"%s\".", file);

}



\end{lstlisting}


\begin{center}
\begin{tabbing}

\end{tabbing}
\end{center}


\pagebreak

\subsection{Pseudocode description}
\textbf{}
\indent The {\bf read\_file} function is for reading the content from a file under the same folder as our compiled program. It accepts 1 parameter, the name of the file from which we will have our content read. 

\indent The {\bf print\_file} function is for printing to console the current content which we have or have not modified. It has no parameters. 

\indent The {\bf save\_to\_file} is for saving the current modified content to a file under the same folder. It accepts 1 parameter, the name of the new file where the content will be saved. 


\section{Application Design}
\subsection{Main}
\textbf{}
\indent The {\bf main} of my program contains a {\bf while} loop so the user will be forced to choose a valid option. He has the option to choose from ten different options and if the user doesn't load a file he won't be able to use the options.


\subsection{Input Data}
\textbf{}
\indent For my program, input data are "G\_DECISION", "G\_DECISION\_STRING", "G\_DECISION\_STRING\_REPLACE"."G\_DECISION" is the choice that you have to make in order to choose an option in main and in some cases will be overwrited in the option chosen, "G\_DECISION\_STRING" is used for telling to or from which file do you want to save or read, in some cases is used to tell the program which word do you want to find or replace. "G\_DECISION\_STRING\_REPLACE" variable is used to tell the functions which word do you want to replace with.

\subsection{Output Data}
\textbf{}
\indent The data outputs resulted from functions processing. The functions include saving, printing to console, literacy.




\pagebreak

\subsection{Functions used}
\textbf{}
\indent{\bf void read\_file(char file[G\_MAX\_WORD\_LENGTH])} function is for reading the content from a file under the same folder as our compiled program. It accepts 1 parameter, the name of the file from which we will have our content read. 

{\bf void print\_file()} function is for printing to console the current content which we have or have not modified. It has no parameters. 

{\bf void save\_to\_file(char file[G\_MAX\_WORD\_LENGTH])} is for saving the current modified content to a file under the same folder. It accepts 1 parameter, the name of the new file where the content will be saved. 

{\bf void find\_word(char word\_to\_find[G\_MAX\_WORD\_LENGTH])} function is used to find information about one particular word. Information like: number of occurrences, where you can find it in text or if it exists.

{\bf void find\_number\_occurrence(char word\_to\_find[G\_MAX\_WORD\_LENGTH])} function is used to find only the number of occurrences of our word.

{\bf void replace\_word(char word\_to\_replace[G\_MAX\_WORD\_LENGTH], char word\_replace\_with[G\_MAX\_WORD\_LENGTH])} functions is used to replace all occurrences of an word with a given word.

{\bf void replace\_word(char word\_to\_replace[G\_MAX\_WORD\_LENGTH], char word\_replace\_with[G\_MAX\_WORD\_LENGTH], unsigned int occurrence\_number)} function is used to replace our word with the given word only if the occurrence match our given number.

{\bf void sort\_to\_file\_occurrence(char file[G\_MAX\_WORD\_LENGTH])} function that saves our content to a file by creating a sorted list of words by the number of occurrences.

{\bf void sort\_to\_file\_alphabetical(char file[G\_MAX\_WORD\_LENGTH])} function that saves our content to a file by creating an alphabetical list of words.

{\bf unsigned int return\_find\_number\_occurrence(char word\_to\_find[G\_MAX\_WORD\_LENGTH])} that returns the number of occurrences instead of printing it, it's used to sort by the number of occurrences.


\section{Source code}
\textbf{}
\indent My program is called "Text Editor Library". It is created in C99 standard.

The code is compiled with the following compiler: "GNU GCC Compiler"



\section{Experiments and results}
\subsection{GCC Compiler}
\textbf{}
\indent For GCC compiler I read the content from a file.

It runs as follow: \\ \\
\includegraphics[scale=1]{e1} \\
\includegraphics[scale=1]{e2} \\ \\
\includegraphics[scale=1]{e3} \\
\includegraphics[scale=1]{e4} \\ \\
\includegraphics[scale=1]{e5}

\pagebreak

\section{Conclusions}
\textbf{}
\indent The dynamic allocation helps optimizing the program as it allocate memory only as much as the program needs but for strings it's hard to work with.


% bibliography
\begin{thebibliography}{9}

    \bibitem{wiki}
     {\bf Robert I. Pitts} \\
     \url{https://www.cs.bu.edu/teaching/cpp/string/array-vs-ptr/}


\end{thebibliography}

\end{document}

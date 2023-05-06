#ifndef KAMIL_DOCUMENT_H
#define KAMIL_DOCUMENT_H


/**
 * @file Document.h
 *
 * @brief Interface file for the Document class
 *
 * The Document.h file is responsible for all File I/O between the system and the program
 * it can read and write files and will also push some work off to python scripts to handle config files
 */

#include <filesystem>
#include <cstdlib>
#include <fstream>

/**
 * @brief Document class
 */
class Document{
public:
    /**
     * @brief Constructor for Document class
     */
    Document();

    /**
     * @brief Constructor for Document class
     * @param fileP - file path 
     */
    Document(std::string fileP);

    /**
     * @brief initialise the file
     * TODO: overload this with file path
     */
    void init();

    /**
     * @brief read the file
     */
    void readFile();

    /**
     * @brief get the relative path
     */
    std::string getRelPath();

    /**
     * @brief get the relative path
     */
    std::string getAbsPath();

    /** 
     * @brief create the file
     */
    void createFile();

    /**
     * @brief create a directory
     */
    void createDir();

    /**
     * @brief save to a file
     */
    bool saveFile(const std::string& filename);

    /**
     * @brief if the file has changed
     * @return bool - true if file has changed
     */
    bool hasChanged();

    // void addTextToPos(std::string txt, int pos);

private:
    std::string relPath; /**< relative path */
    std::string absPath; /**< absolute path */

    std::string buffInfo; /** buffer information (the file text) */

    bool docChanged; /**< if the file has changed */
};
#endif // KAMIL_DOCUMENT_H

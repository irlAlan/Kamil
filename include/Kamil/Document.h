#ifndef KAMIL_DOCUMENT_H
#define KAMIL_DOCUMENT_H

/**
 * @file Document.h
 *
 * @brief Interface file for the Document class
 *
 * The Document.h file is responsible for all File I/O between the system and
 * the program it can read and write files and will also push some work off to
 * python scripts to handle config files
 */

#include <cstdlib>
#include <filesystem>
#include <fstream>

/**
 * @brief Document class
 */
class Document {
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
   * @param void
   * @return void
   */
  void init();

  /**
   * @brief initialise the file
   * @param inF - file location
   * @return void
   */
  void init(std::string inF);

  /**
   * @breif get the count of lines
   * @param void
   * @return int - line count
   */
  int getLineCount();

  /**
   * @brief read the file
   * @param void
   * @return string containing the file info
   */
  std::string readFile();

  /**
   * @brief get the relative path
   * @param void
   * @return string for relative path
   */
  std::string getRelPath();

  /**
   * @brief get the relative path
   * @param void
   * @return string for absolute path
   */
  std::string getAbsPath();

  /**
   * @brief create the file
   * @param std::string - file name 
   * @return void
   */
  void createFile(std::string filename);

  /**
   * @brief create a directory
   * @param std::string directory name
   * @return void
   */
  void createDir(std::string dirNmae);

  /**
   * @brief save to a file
   * @param string - filename to save to
   * @return bool - true if saved
   */
  bool saveFile(const std::string &filename);

  /**
   * @brief save to a file
   * @param void
   * @return bool - true if saved
   */
  bool saveFile();

  /**
   * @brief save file infor to buffer
   * @param string buffer info
   * @return void 
   */
  void setBuffInfo(std::string info);

  /**
   * @brief if the file has changed
   * @param void
   * @return bool - true if file has changed
   */
  bool hasChanged();

  /**
   * @brief set file has changed
   * @param void
   * @return void
   */
  void setChange();

  /**
   * @brief check if theres text in the file 
   * @param void
   * @return bool - true if contains text
   */
  bool docHasText();

  // void addTextToPos(std::string txt, int pos);

private:
  std::string relPath; /**< relative path */
  std::string absPath; /**< absolute path */

  std::string buffInfo; /** buffer information (the file text) */

  bool docChanged; /**< if the file has changed */
};
#endif // KAMIL_DOCUMENT_H

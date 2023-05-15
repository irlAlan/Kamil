#ifndef KAMIL_DOCUMENT_H
#define KAMIL_DOCUMENT_H

/**
 * @file Document.h
 *
 * @brief Interface file for the Document class
 *
 * The Document.h file is responsible for all File I/O between the system and
 * the program it can read and write files.
 * It is also responsible for the configuration file in the 'config.toml' format
 */

#include "SFML/Graphics/Color.hpp"
#include <cstdlib>
#include <filesystem>
#include <fstream>


/**
 * @brief Document class
 */
class Document {
public:
    /**
     * @brief a struct for the Theme
     *
     * A struct containing all the information for the Theme of the Text editor
     * @param sf::Color - background colour
     * @param sf::Color - font colour
     */
    struct Theme{
        sf::Color bcol;
        sf::Color fcol;
    };

    /**
     * @brief A struct for the configuration
     *
     * A struct containing all the necessary information for the configuration
     * of the Text editor
     *
     * @param std::string - The command to run the programs 
     * i.e. "python3" will execute python3
     * @param std::string - The font
     * @param Theme the struct containing theme information
     */
    struct Config{
        std::string cmd;
        std::string font;
        Theme theme;
    };
  /**
   * @brief Constructor for Document class
   * png/Document/docConst1.png
   *  eps/Document/docConst1.eps Constructor for Document
   */
  Document();

  /**
   * @brief Constructor for Document class
   * @param fileP - file path
   *
   * png/Document/docConst2.png
   * eps/Document/docConst2.eps Constructor for Document
   */
  Document(std::string fileP);

  /**
   * @brief initialise the file
   * @param void
   * @return void
   *
   * png/Document/docInit1.png
   * eps/Document/docInit1.eps init method for Document
   */
  void init();

  /**
   * @brief initialise the file
   * @param inF - file location
   * @return void
   *
   * png/Document/docInit2.png
   * eps/Document/docInit2.eps init method for Document
   */
  void init(std::string inF);

  /**
   * @brief read the file
   * @param void
   * @return string containing the file info
   *
   * html png/Document/docrFile.png
   * latex eps/Document/docrFile.eps readFile method for Document
   */
  std::string readFile();

  /**
   * @brief get the relative path
   * @param void
   * @return string for relative path
   *
   */
  std::string getRelPath();

  /**
   * @brief get the relative path
   * @param void
   * @return string for absolute path
   *
   * html png/Document/docgAbsPath.png
   * latex eps/Document/docgAbsPath.eps
   */
  std::string getAbsPath();


  /**
   * @brief check if the config.toml exist
   * @param void
   * @return bool - true if config.toml exists
   *
   * html png/Document/findConfig.png
   * latex eps/Document/findConfig.eps
   */
  bool findConfig();


  /**
   * @brief create the file
   * @param std::string - file name 
   * @return void
   *
   * html png/Document/docCreateFile.png
   * latex eps/Document/docCreateFile.eps
   */
  void createFile(std::string filename);

  /**
   * @brief save to a file
   * @param string - filename to save to
   * @return bool - true if saved
   *
   * html png/Document/docSaveFile1.png
   * latex eps/Document/docSaveFile1.eps
   */
  bool saveFile(const std::string &filename);

  /**
   * @brief save to a file
   * @param void
   * @return bool - true if saved
   *
   * html png/Document/docSaveFile2.png
   * latex eps/Document/docSaveFile2.eps
   */
  bool saveFile();

  /**
   * @brief save file infor to buffer
   * @param string buffer info
   * @return void 
   *
   * html  png/Document/docSetBuffInfo.png
   * latex eps/Document/docSetBuffInfo.eps
   */
  void setBuffInfo(std::string info);

  /**
   * @brief if the file has changed
   * @param void
   * @return bool - true if file has changed
   *
   * html  png/Document/dochChange.png
   * latex eps/Document/dochChange.eps
   *
   */
  bool hasChanged();

  /**
   * @brief set file has changed
   * @param void
   * @return void
   * 
   * html  png/Document/docsetChange.png
   * latex eps/Document/docsetChange.eps
   */
  void setChange();

  /**
   * @brief retrieves information from config.toml
   * 
   * searches through the config.toml files for the necessary information
   * and extracts it.
   *
   * @param void
   * @return Config - config.toml information
   *
   * html  png/Document/docgConf.png
   * latex eps/Document/docgConf.eps
   */
  Config getConfig();


private:
  std::string relPath; /**< relative path */
  std::string absPath; /**< absolute path */

  std::string buffInfo; /** buffer information (the file text) */

  bool docChanged; /**< if the file has changed */
};
#endif // KAMIL_DOCUMENT_H

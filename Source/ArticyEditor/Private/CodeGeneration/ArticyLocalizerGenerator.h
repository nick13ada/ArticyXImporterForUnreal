﻿//  
// Copyright (c) 2024 articy Software GmbH & Co. KG. All rights reserved.  
//

#pragma once

class UArticyImportData;
struct FArticyType;
class FString;
class CodeFileGenerator;

/**
 * @class ArticyLocalizerGenerator
 * @brief A utility class for generating ArticyLocalizer code from import data.
 */
class ArticyLocalizerGenerator
{
public:
    /**
     * @brief Generates the ArticyLocalizer class from the given import data.
     *
     * This function creates necessary code files for the ArticyLocalizer
     * and updates project configurations to include required directories.
     *
     * @param Data The import data used to generate the ArticyLocalizer.
     * @param OutFile The name of the output file generated by the process.
     */
    static void GenerateCode(const UArticyImportData* Data, FString& OutFile);

private:
    /**
     * @brief Private default constructor to prevent instantiation.
     */
    ArticyLocalizerGenerator() {}

    /**
     * @brief Private destructor.
     */
    ~ArticyLocalizerGenerator() {}

    /**
     * @brief Adds a key-value pair to the DefaultGame.ini
     * 
     * @param Key Key to add .
     * @param Value Value to add.
     */
    static void AddIniKeyValue(const FString& Key, const FString& Value);

    /**
     * @brief Iterates through string tables in a given directory and generates code for each.
     *
     * This function finds CSV files in the specified directory and generates
     * code to register and load these string tables.
     *
     * @param Header The code file generator used to output the generated code.
     * @param DirectoryPath The path to the directory containing string table CSV files.
     * @param Indent Whether to indent the generated code lines (default is false).
     */
    static void IterateStringTables(CodeFileGenerator* Header, const FString& DirectoryPath, bool Indent = false);

    /**
     * @brief Iterates over string tables in a given directory and generates code for each table.
     *
     * This function registers and loads string tables from CSV files found in the specified directory path.
     *
     * @param Header The code file generator to write string table registration code.
     * @param DirectoryPath The path to the directory containing string table CSV files.
     * @param Indent Whether to indent the generated code lines.
     */
    static void IterateLocalizationDirectories(CodeFileGenerator* Header, const FString& LocalizationRoot);

    /**
     * @brief Modifies an INI file by adding a new value to a specified section and key.
     *
     * Reads the existing value for a section and key in the INI file, appends a
     * new value if it's not already present, and writes the updated value back to the file.
     *
     * @param IniFilePath The path to the INI file to be modified.
     * @param SectionName The section in the INI file to be modified.
     * @param KeyName The key within the section to be modified.
     * @param NewValue The new value to be added to the existing entry.
     */
    static void ModifyIniFile(const FString& IniFilePath, const FString& SectionName, const FString& KeyName, const FString& NewValue);
};

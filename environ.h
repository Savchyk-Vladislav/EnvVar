#ifndef ENVIRON_H
#define ENVIRON_H


class Environ {
public:
    void displayEnv();
    void displayVarVal(char* var);
    void setVarVal(char* varVal);
    void assignVarVal(char* var, char* val);
    void deleteVar(char* var);
    void clearEnv();
    void displayHelp();
};

#endif // ENVIRON_H

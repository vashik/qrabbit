#ifndef DIRSTREE_H
#define DIRSTREE_H

#include "fileinfo.h"

struct DirsTree;
struct DirsTree {
    QDir current;
    QString relativePath;
    QList<DirsTree> childDirs;
    QList<FileInfo> files;
    void clear()
    {
        childDirs.clear();
        files.clear();
    }
    bool operator== (const DirsTree &other ) const {
        if(other.current == current)
            return true;
        else
            return false;
    }
};
#endif // DIRSTREE_H

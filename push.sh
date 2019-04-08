#!/bin/bash
chmod +x push.sh

git add .
git commit -m $@
git push
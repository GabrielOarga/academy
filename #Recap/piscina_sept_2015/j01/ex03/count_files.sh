find . | wc -l | tr ' ' 'y' | rev | cut -d y -f 1 | rev

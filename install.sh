#!/bin/bash

installnpmbower(){
  cd "${1}"
  npm install
  bower install
  cd ..
}
main(){
if hash brew 2>/dev/null; then
  echo "homebrew is installed"
else
  echo "installing homebrew"
  ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
  brew doctor
fi

if hash node 2>/dev/null; then
  echo "node is installed"
else
  echo "installing node"
  brew install node
fi

if hash grunt 2>/dev/null; then
  echo "grunt-cli is installed"
else
  echo "installing grunt-cli"
  npm install -g grunt-cli
fi

if hash bower 2>/dev/null; then
  echo "bower is installed"
else
  echo "installing bower"
  npm install -g bower
fi

if hash spark 2>/dev/null; then
  echo "spark-cli is installed"
else
  echo "installing spark-cli"
  npm install -g spark-cli
fi

echo "Cloning Workshop repo"
git clone https://github.com/FH-Potsdam/2014-2015-WiSe-spark-core-workshop.git
echo "cd into it"
cd 2014-2015-WiSe-spark-core-workshop
echo "init submodules"
git submodule init && git submodule update
echo "init node_modules & bower_components"
cd spark-ajax; npm install && bower install
cd ..
cd spark-client-side; npm install && bower install
# for D in *; do [ -d "${D}" ] && installnpmbower "${D}"; done
}

main
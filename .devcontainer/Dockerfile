# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.191.1/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-11, debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN curl -fsSL https://deb.nodesource.com/setup_14.x | bash - && \
  apt-get install -y nodejs python3-pip && \
  npm install -g atcoder-cli && \
  python3 -m pip install online-judge-tools

ENV CPLUS_INCLUDE_PATH=/workspaces/kyoprocpp/ac-library
ENV PATH=$PATH:/workspaces/kyoprocpp/bin

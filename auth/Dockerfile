#docker build -t "auth" .
#docker run --name "auth" -d -p 8000:8000 [IMAGE]

FROM ubuntu:16.04
#installation
RUN dpkg --add-architecture i386
RUN apt-get update && apt-get upgrade -y 
RUN apt-get install -y socat build-essential libc6:i386 libncurses5:i386 libstdc++6:i386

#user
RUN adduser --disabled-password --gecos '' auth
RUN chown -R root:auth /home/auth/
RUN chmod 750 /home/auth
RUN chmod 740 /usr/bin/top
RUN chmod 740 /bin/ps
RUN chmod 740 /usr/bin/pgrep
RUN export TERM=xterm

WORKDIR /home/auth/

COPY auth /home/auth
COPY flag /home/auth

RUN chown root:auth /home/auth/flag
RUN chmod 440 /home/auth/flag

RUN strip -s auth

EXPOSE 8000
CMD su auth -c "socat -T10 TCP-LISTEN:8000,reuseaddr,fork EXEC:/home/auth/auth"

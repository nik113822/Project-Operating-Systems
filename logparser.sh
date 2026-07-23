#!/bin/bash
# Νικόλαος Παπαδούρης, 1090040
# Αλέξανδρος Κολλώσης, 1084562
# Μίλτος Κουράκος, 1084621
# Νικόλαος Ανδρομιδάς, 1084641

if [ -z "$1" ]
then
    echo "1090040|1084562|1084621|1084641"
    exit 0
elif [ -n "$1" ]
then
    onom=$1
fi

match() {
    echo -n "Mozilla"; echo -n " "; grep -c "Mozilla" access.log
    echo -n "Chrome"; echo -n " "; grep -c "Chrome" access.log
    echo -n "Safari"; echo -n " "; grep -c "Safari" access.log
    echo -n "Edg"; echo -n " "; grep -c "Edg" access.log
}

count_browsers() {
    echo ""
    match
}

mining_usernames() {
    awk '{print $3}' access.log | sort | uniq -c | sort -k2
    echo "Give me a user name:"
    read -r usr

    case $usr in
        root) cat access.log | grep "root" ;;
        -) cat access.log | grep "-" ;;
        user1) cat access.log | grep "user1" ;;
        user2) cat access.log | grep "user2" ;;
        user3) cat access.log | grep "user3" ;;
        president) cat access.log | grep "president" ;;
        admin) cat access.log | grep "admin" ;;
        *) echo "de brethike kanenas xrhsths" ;;
    esac
}

case ${onom:-} in
    "access.log")
        cat access.log
        ;;
    "access.log--usrid")
        mining_usernames
        ;;
    "access.log-method")
        echo -n "Dose methodo:"
        read -r meth
        if [[ $meth == "get" ]]
        then
            cat access.log | grep "GET"
        elif [[ $meth == "post" ]]
        then
            cat access.log | grep "POST"
        else
            echo "Wrong Method Name"
        fi
        ;;
    "access.log--servprot")
        echo "Enter server protocol:"
        read -r srvp
        if [[ $srvp == "IPv4" ]]
        then
            cat access.log | grep "127.0.0.1"
        elif [[ $srvp == "IPv6" ]]
        then
            cat access.log | grep "::1"
        else
            echo "Wrong Network Protocol"
        fi
        ;;
    "access.log--browsers")
        count_browsers
        ;;
    "access.log--datum")
        echo "Give me a date:"
        read -r dat
        case $dat in
            "Jan") cat access.log | grep "Jan" ;;
            "Feb") cat access.log | grep "Feb" ;;
            "Mar") cat access.log | grep "Mar" ;;
            "Apr") cat access.log | grep "Apr" ;;
            "May") cat access.log | grep "May" ;;
            "Jun") cat access.log | grep "Jun" ;;
            "Jul") cat access.log | grep "Jul" ;;
            "Aug") cat access.log | grep "Aug" ;;
            "Sep") cat access.log | grep "Sep" ;;
            "Oct") cat access.log | grep "Oct" ;;
            "Nov") cat access.log | grep "Nov" ;;
            "Dec") cat access.log | grep "Dec" ;;
            *) echo "Wrong date" ;;
        esac
        ;;
    *)
        echo "Enter filename:"
        read -r fil
        if [ "${fil##*.}" = "log" ]
        then
            echo "sosto arxeio"
        elif [ "${fil##*.}" != "log" ]
        then
            echo "Wrong File Argument"
        fi
        ;;
esac

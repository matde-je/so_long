int main(int argc, char **argv)
{
    if (argc != 2)
        error("Invalid args");
    check_map(*argv[1]);

}

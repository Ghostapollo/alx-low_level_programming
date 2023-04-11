#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

#define BUF_SIZE 128

/**
 * print_error - Prints the error message to standard error output
 * and exits the program with an exit code of 98.
 * @message: Pointer that contains an error message to be printed
 */
void print_error(char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header -  Print the ELF header
 * information of a given ELF file.
 * Parameters:
 * @header: a pointer to the ELF header structure
 */
void print_elf_header(Elf32_Ehdr *header)
{
	int i;
	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             ");

	if (header->e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
	}
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
	}
	else
	{
		printf("Invalid class\n");
	}
	printf("  Data:                              ");

	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
	}
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
	}
	else
	{
		printf("Invalid data encoding\n");
	}
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");

	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V ABI\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX ABI\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD ABI\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux ABI\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris ABI\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX ABI\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD ABI\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64 UNIX ABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture ABI\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) ABI\n");
			break;
		default:
			printf("Unknown OS/ABI\n");
			break;
	}
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");

	switch (header->e_type)
	{
		case ET_NONE:
			printf("No file type\n");
			break;
		case ET_REL:
			printf("Relocatable file\n");
			break;
		case ET_EXEC:
			printf("Executable file\n");
			break;
		case ET_DYN:
			printf("Shared object file\n");
			break;
		case ET_CORE:
			printf("Core file\n");
			break;
		default:
			printf("Unknown file type\n");
			break;
	}
	printf("  Entry point address:               0x%x\n", header->e_entry);
	printf("  Start of program headers:          %d (bytes into file)\n", header->e_phoff);
	printf("  Start of section headers:          %d (bytes into file)\n", header->e_shoff);
	printf(" Flags: 0x%x\n", header->e_flags);
	printf(" Size of this header: %d (bytes)\n", header->e_ehsize);
	printf(" Size of program headers: %d (bytes)\n", header->e_phentsize);
	printf(" Number of program headers: %d\n", header->e_phnum);
	printf(" Size of section headers: %d (bytes)\n", header->e_shentsize);
	printf(" Number of section headers: %d\n", header->e_shnum);
	printf(" Section header string table index: %d\n", header->e_shstrndx);
}

/**
 * print_elf_header_info - prints the information in the ELF header
 * @header: pointer to the ELF header structure
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	printf("Magic:   ");
	printf("Class:                             %s\n",
		header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
		header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid class");
	printf("Data:                              %s\n",
		header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
		header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid data encoding");
	printf("Version:                           %d%s\n",
		header->e_ident[EI_VERSION], header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("OS/ABI:                            ");
	printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:                              ");
	printf("Entry point address:               %#lx\n", (unsigned long)header->e_entry);
}

/**
 * main - reads an ELF header and prints its information
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int j;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	j = open(argv[1], O_RDONLY);
	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	if (read(j, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(j);
		return (98);
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		dprintf(STDERR_FILENO, "Error: File %s is not an ELF file\n", argv[1]);
		close(j);
		return (98);
	}

	print_elf_header_info(&header);

	close(j);
	return (0);
}

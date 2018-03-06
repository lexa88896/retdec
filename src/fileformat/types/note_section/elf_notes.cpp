/**
 * @file src/fileformat/types/note_section/elf_note.cpp
 * @brief Class for ELF note segment.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#include "retdec/fileformat/types/note_section/elf_notes.h"

namespace retdec {
namespace fileformat {

/**
 * Check if note is system reserved empty note
 * @return @c true if note is empty, @c false otherwise
 */
bool ElfNote::isEmptyNote() const
{
	return name.empty();
}

/**
 * Constructor
 * @param assocSecSeg pointer to associated section or segment
 */
ElfNotes::ElfNotes(const SecSeg* assocSecSeg) : secSeg(assocSecSeg)
{
}

/**
 * Destructor
 */
ElfNotes::~ElfNotes()
{
}

/**
 * Add one note entry (move)
 * @param note note entry
 */
void ElfNotes::addNote(ElfNote&& note)
{
	notes.emplace_back(std::move(note));
}

/**
 * Add one note entry (copy)
 * @param note note entry
 */
void ElfNotes::addNote(const ElfNote& note)
{
	notes.emplace_back(note);
}

/**
 * Get notes for segment or section
 * @return vector of notes
 */
std::vector<ElfNote> ElfNotes::getNotes() const
{
	return notes;
}

/**
 * Get file offset of section or segment
 * @return file offset
 */
std::size_t ElfNotes::getSecSegOffset() const
{
	return secSeg->getOffset();
}

/**
 * Get length of section or segment in file
 * @return size in file
 */
std::size_t ElfNotes::getSecSegLength() const
{
	return secSeg->getSizeInFile();
}

/**
 * Get name of section (only sections have name)
 * @return section name or empty string if name is missing
 */
std::string ElfNotes::getSectionName() const
{
	return secSeg->getName();
}

/**
 * Check if notes belong to named section
 * @return @c true if notes belong to named section, @c false otherwise
 */
bool ElfNotes::isNamedSection() const
{
	return !secSeg->getName().empty();
}

/**
 * Check if object contains any notes
 * @return @c true if object contains any notes, @c false otherwise
 */
bool ElfNotes::isEmpty() const
{
	return notes.empty();
}


} // namespace fileformat
} // namespace retdec
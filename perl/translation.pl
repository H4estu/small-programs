# 
# File: translation.pl
# Sample DNA transcription/translation routine.
# Taken from MIT Genomics and Comp Bio open source course, lecture 2
# 
# Last edit: 31 Aug 2016

# Genome
$DNA_seq = "CAGTCGACCCCAACGGCCCCTAGATTCCCCCTTCCCGTCTGCCCAACGCTGCCCGCGTGT
CTTCCCCCTTGCCCCCGTTCCGGACCATGGGGGTCGGGCGTAGCCCCCCGCCTTCGATGG
CTAAGACGCGGATTGCTCTGCGGGGTTCCTGCAGCCGCCCGGGTCGATTGGCCACCATGC
GCGCCCCGCTCCGCAAGCACCGAGAGTGTCGTGCGCATCTACCGGCGTCGGCCCTCCTCC
GCGTCCTGGCGACCTTCCCTCACCCCCCGCCGCCTCATCACTACCCACTTCGGGCTTTCC
GCATCTGACGGGCCTCCGGTTCCATGCGTCCTCGGCACTCGCCCCCCGTCGCCTTAGGGC
CCGCCGGGATTGGTCTTCTCTGGGAGGGATTTCACCGGCGACTCCCACGGTTACGTGGGT
TTGTCGGTCCGCCGTGTGGACGTTGTGCTGAGACCCACGGCCGGTAATAGGTGCTCCACC
CGTGGGCGCGGTCTCGCTGACGTCGGATGGCCACGAATGGTCTCGTGGAGCTGGGCGGCT
CTCGCGGTCCACGACCCAGCGACTGTCCGCCCCTCTTGGAGCTTCAACCCGATCTGCACC
GACACGCTCTCCGGGTCGATCGTCGCGTCGGGTTGGGCGGTCCTCGCGGCACCCAGTCCT
TCCAATCAGCCATCCAGGCCCCCCCGTCGATCGTCGCCTAGGCACGGCGACAGACCGCCG
GTTGCGCCTCTCTTTGGCGTATGAGCGGGCCCAATCAAGCCCACCGCCCGTCGGGCTAGC
CTGTATTTTCCCCGCCGTCATCCGCGATCCCAAGTTCTACCGTGCCACGTCTTACTACTA
TGCGACGTCCTCCAGGTAGCCCGTAGGATGCCACCCCGACCCCCTTGTCCTCGCGGGTTA
GCCGGTTACCCGGCGGAGCTGATCCAAGTCGCGGTGTCGCCCGCTGCTAGTATCGTGGCT
GGCTCTGTGGGGGCTCGCCTCCGGCTCTGTTTCAACAACCAGTAA";

# Transcription
$RNA_seq = $DNA_seq;
$RNA_seq =~ s/T/U/gi;   # change T to U in RNA sequence
$RNA_seq =~ s/[\h\v]+/ /g;  # change line breaks to single white spaces
$RNA_seq =~ tr/ //ds;   # remove all whitespace between "words"
print "$RNA_seq\n";

# Translation
$position = 0;
while (substr $RNA_seq,$position,3) {
    $codon = substr $RNA_seq,$position,3;
    $translated = translate_codon($codon);
    print "$codon : $translated\n";
    $position = $position + 3;
}

sub translate_codon {
    if ($_[0] =~ /AUU|AUC|AUA/i) {return Isoleucine;}
    if ($_[0] =~ /CU.|UUA|UUG/i) {return Leucine;}
    if ($_[0] =~ /GU./i) {return Valine;}
    if ($_[0] =~ /UUU|UUC/i) {return Phenylalanine;}
    if ($_[0] =~ /AUG/i) {return Methionine;}
    if ($_[0] =~ /GC./i) {return Alanine;}
    if ($_[0] =~ /UGC|UGU/i) {return Cysteine;}
    if ($_[0] =~ /GG./i) {return Glycine;}
    if ($_[0] =~ /CC./i) {return Proline;}
    if ($_[0] =~ /AC./i) {return Threonine;}
    if ($_[0] =~ /UC.|AGU|AGC/i) {return Serine;}
    if ($_[0] =~ /UAU|UAC/i) {return Tyrosine;}
    if ($_[0] =~ /UGG/i) {return Tryptophan;}
    if ($_[0] =~ /CAA|CAG/i) {return Glutamine;}
    if ($_[0] =~ /AAU|AAC/i) {return Asparagine;}
    if ($_[0] =~ /CAU|CAC/i) {return Histidine;}
    if ($_[0] =~ /GAA|GAG/i) {return Glutamic_acid;}
    if ($_[0] =~ /GAU|GAC/i) {return Aspartic_acid;}
    if ($_[0] =~ /AAA|AAG/i) {return Lysine;}
    if ($_[0] =~ /CG.|AGA|AGG/i) {return Arginine;}
    if ($_[0] =~ /UAA|UAG|UGA/i) {return STOP;}
}